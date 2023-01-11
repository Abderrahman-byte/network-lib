////////////////////////////////////////////////////////////
/// \mainpage Network Library Documentation
///
/// \section welcome Welcome
/// Welcome to the official Network Library documentation. Here you will find a detailed
/// view of all the Library classes and functions. <br/>
///
/// \section example Short example
/// Here is a short example, to show you how simple it is to use netlib:
///
/// \code
///
/// #include <libnet/Socket.hpp>
///
/// int main()
/// {
///     // Create Socket
///     Socket socket(SocketType::tcp);
///
///     // Bind Socket to an ip address and port
///     socket.bind("127.0.0.1", 8000);
///     
///     // Start listenning
///     socket.listen();
///
///
///     return EXIT_SUCCESS;
/// }
/// \endcode
////////////////////////////////////////////////////////////
