
// File: GuiChatServer.java
import javax.swing.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

class ServerChat implements ActionListener, Runnable {
    // Characteristics
    JFrame fobj;
    JButton bobj;
    JTextField tobj;
    JLabel Textlabel, Messagelabel;

    // Networking Components
    ServerSocket ssobj;
    Socket sobj;
    PrintStream pobj;
    BufferedReader bobj1; // Reader for incoming messages

    public ServerChat(String title, int width, int height) {
        fobj = new JFrame(title);

        Textlabel = new JLabel("Enter Message for Client:");
        Textlabel.setBounds(20, 50, 200, 30);

        tobj = new JTextField();
        tobj.setBounds(200, 50, 150, 30);

        bobj = new JButton("Send");
        bobj.setBounds(150, 150, 100, 30);

        // This label will display received messages
        Messagelabel = new JLabel("Waiting for client...");
        Messagelabel.setBounds(50, 200, 300, 30);

        fobj.add(bobj);
        fobj.add(tobj);
        fobj.add(Textlabel);
        fobj.add(Messagelabel);

        bobj.addActionListener(this); // Register button listener

        fobj.setLayout(null);
        fobj.setSize(width, height);
        fobj.setVisible(true);
        fobj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    // Method to handle sending message when 'Send' button is clicked
    public void actionPerformed(ActionEvent aobj) {
        if (sobj == null) {
            Messagelabel.setText("Client not connected yet.");
            return;
        }

        try {
            String message = tobj.getText();
            if (!message.isEmpty()) {
                pobj.println(message); // Send message to client
                
                tobj.setText(""); // Clear text field
            }
        } catch (Exception e) {
            Messagelabel.setText("Error sending message.");
        }
    }

    // Run method to handle accepting connection and continuously receiving messages
    public void run() {
        try {
            ssobj = new ServerSocket(5100);
            Messagelabel.setText("Server is waiting at port 5100...");
            System.out.println("Server is waiting at port 5100");

            sobj = ssobj.accept(); // Blocking call, waits for client
            Messagelabel.setText("Client connected successfully!");
            System.out.println("Client request gets accepted successfully");

            // Setup I/O streams
            pobj = new PrintStream(sobj.getOutputStream());
            bobj1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));

            String str;
            // Continuous loop to read messages from client
            while ((str = bobj1.readLine()) != null) {
                // Use SwingUtilities.invokeLater to update GUI from a non-event thread
                final String receivedMessage = str;
                SwingUtilities.invokeLater(() -> {
                    Messagelabel.setText("Client says: " + receivedMessage);
                });
            }

        } catch (IOException e) {
            SwingUtilities.invokeLater(() -> {
                Messagelabel.setText("Connection closed or error: " + e.getMessage());
            });
            System.out.println("Server error: " + e.getMessage());
        } finally {
            try {
                if (sobj != null) sobj.close();
                if (ssobj != null) ssobj.close();
            } catch (IOException e) {
                // Ignore
            }
        }
    }
}

class GuiChatServer {
    public static void main(String A[]) throws Exception {
        ServerChat cobj = new ServerChat("Server", 400, 300);
        // Start the connection handling logic in a separate thread
        Thread t = new Thread(cobj);
        t.start();
    }
}