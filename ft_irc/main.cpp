#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <poll.h>
#include <vector>

int main()
{
	// Create a socket
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1)
	{
		std::cerr << "Can't create a socket! Quitting" << std::endl;
		return -1;
	}

	// Bind the ip address and port to a socket
	sockaddr_in hint = {};
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

	if (bind(fd, (sockaddr*)&hint, sizeof(hint)) == -1)
	{
		std::cerr << "Can't bind" << std::endl;
		return -1;
	}

	// Tell Winsock the socket is for listening
	if (listen(fd, SOMAXCONN) == -1)
	{
		std::cerr << "Can't listen" << std::endl;
		return -1;
	}

	std::vector<pollfd> poll_fds;

	pollfd pfd = {};
	pfd.fd = fd;
	pfd.events = POLLIN;
	poll_fds.push_back(pfd);

//	// Wait for a connection
//	sockaddr_in client;
//	socklen_t clientSize = sizeof(client);
//
//	int clientSocket = accept(fd, (sockaddr*)&client, &clientSize);
//
//	char host[NI_MAXHOST];      // Client's remote name
//	char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on
//
//	memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
//	memset(service, 0, NI_MAXSERV);

//////		if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
//////		{
//////			cout << host << " connected on port " << service << endl;
//////		}
//////		else
//////		{
//////			inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
//////			cout << host << " connected on port " << ntohs(client.sin_port) << endl;
//////		}

//	// Close listening socket
//	close(fd);

	// While loop: accept and echo message back to client
	char buf[4096];


	int					return_state;
	while (true)
	{
		return_state = poll(&(poll_fds[0]), poll_fds.size(), 1000);
		if (return_state == -1)
		{
			std::cerr << "Error poll" << std::endl;
			continue;
		}
		if (return_state == 0)
		{
			std::cerr << "Timeout 100 ms poll" << std::endl;
			continue;
		}

		//*************
		std::cout << "Received data: " << std::string(buf) << std::endl;


		memset(buf, 0, 4096);

		// Wait for client to send data
		int bytesReceived = recv(clientSocket, buf, 4096, 0);
		if (bytesReceived == -1)
		{
			std::cerr << "Error in recv(). Quitting" << std::endl;
			break;
		}

		if (bytesReceived == 0)
		{
			std::cout << "Client disconnected " << std::endl;
			break;
		}

		std::cout << std::string(buf, 0, bytesReceived) << std::endl;

		// Echo message back to client
		send(clientSocket, buf, bytesReceived + 1, 0);
	}

	// Close the socket
	close(clientSocket);

	return 0;
}