#include "Renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

GLFWwindow* Renderer::GetWindow()
{
	return window;
}

void Renderer::Init(const int width, const int height, char* titleString)
{
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//set GLFW
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	//create Window
	window = glfwCreateWindow(width, height, titleString, nullptr, nullptr);
	if (!window) {
		cout << "Error al crear la ventana" << endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	//set GLEW and inicializate
	//TODO

	glewExperimental = GL_TRUE;



	if (GLEW_OK != glewInit()) {
		std::cout << "Error al inicializar glew" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	shader = new Shader("shaders/vertexShader.vertexshader", "shaders/fragmentShader.fragmentshader");
}

void Renderer::DrawPolygon()
{
	////activar el culling
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//////GL_CW sentido horario, GL_CCW sentido antihorario
	//glFrontFace(GL_CCW);

	//glBegin(GL_POLYGON);
	//glColor3f(0.f, 1.f, 0.f);
	//glVertex3f(-1.0f, 2.f, 0.f);
	//glVertex3f(-2.0f, 1.f, 0.f);

	//glColor3f(0.f, 0.f, 1.f);
	//glVertex3f(-2.0f, -1.f, 0.f);
	//glVertex3f(-1.0f, -2.f, 0.f);

	//glColor3f(0.5f, 0.5f, 0.5f);
	//glVertex3f(1.0f, -2.f, 0.f);
	//glVertex3f(2.0f, -1.f, 0.f);

	//glColor3f(1.f, 0.f, 0.f);
	//glVertex3f(2.0f, 1.f, 0.f);
	//glVertex3f(1.0f, 2.f, 0.f);
	//glEnd();

	//glDisable(GL_CULL_FACE);
	float vertices[] = {
		0.0f,  0.5f, // Vertex 1 (X, Y)
		0.5f, -0.5f, // Vertex 2 (X, Y)
		-0.5f, -0.5f  // Vertex 3 (X, Y)
	};
	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void Renderer::SetProjectionMatrix()
{
	glViewport(0, 0, screenWidth, screenHeight);
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(1.0, 1.0, 0.8, 1.0);


	//definir la matriz de proyeccion
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10.f, 10.f, -1.0f, 10.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glRotatef((float)glfwGetTime() * 50.f,1.f, 0.f, 0.f);

	//para volver a dejar la rotacion parada
	//glLoadIdentity();

}