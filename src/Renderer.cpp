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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

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
	int screenWithd, screenHeight;
	glfwGetFramebufferSize(window, &screenWithd, &screenHeight);

	//set windows and viewport
	//TODO
	glViewport(0, 0, screenWithd, screenHeight);
	glClear(GL_COLOR_BUFFER_BIT);

	//fondo
	//glClearColor(25.0, 1.0, 1.0, 1.0);

	//shader = new Shader(Settings::VERTEX_SHADER_PATH, Settings::FRAGMENT_SHADER_PATH);
}

void Renderer::DrawTriangle()
{
	float vertices[] = {
		0.0f,	 0.5f, // Vertex 1 (x, y)
		0.5f,	-0.5f, // Vertex 2 (x, y)
	   -0.5f,   -0.5f  // Vertex 3 (x, y)
	};

	GLuint vbo;

	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}