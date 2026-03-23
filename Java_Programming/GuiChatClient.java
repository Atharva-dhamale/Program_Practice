
// File: GuiChatClient.java
import javax.swing.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

class ClientChat implements ActionListener, Runnable 
{
    // Characteristics
    JFrame fobj;
    JButton bobj;
    JTextField tobj;
    JLabel Textlabel, Messagelabel;

    // Networking Components
    Socket sobj;
    PrintStream pobj;
    BufferedReader bobj1; // Reader for incoming messages

    public ClientChat(String title, int width, int height) {
        fobj = new JFrame(title);

        Textlabel = new JLabel("Enter Message for Server:");
        Textlabel.setBounds(20, 50, 200, 30);

        tobj = new JTextField();
        tobj.setBounds(200, 50, 150, 30);

        bobj = new JButton("Send");
        bobj.setBounds(150, 150, 100, 30);

        // This label will display received messages
        Messagelabel = new JLabel("Connecting to server...");
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
        if (sobj == null || sobj.isClosed()) {
            Messagelabel.setText("Not connected to server.");
            return;
        }

        try {
            String message = tobj.getText();
            if (!message.isEmpty()) {
                pobj.println(message); // Send message to server
                
                tobj.setText(""); // Clear text field
            }
        } catch (Exception e) {
            Messagelabel.setText("Error sending message.");
        }
    }

    // Run method to handle connection setup and continuously receiving messages
    public void run() {
        try {
            sobj = new Socket("localhost", 5100);
            Messagelabel.setText("Client connected with server successfully!");
            System.out.println("Client gets connected with server successfully");

            // Setup I/O streams
            pobj = new PrintStream(sobj.getOutputStream());
            bobj1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));

            String str;
            // Continuous loop to read messages from server
            while ((str = bobj1.readLine()) != null) {
                // Use SwingUtilities.invokeLater to update GUI from a non-event thread
                final String receivedMessage = str;
                SwingUtilities.invokeLater(() -> {
                    Messagelabel.setText("Server says: " + receivedMessage);
                });
            }

        } catch (IOException e) {
            SwingUtilities.invokeLater(() -> {
                Messagelabel.setText("Connection closed or error: " + e.getMessage());
            });
            System.out.println("Client error: " + e.getMessage());
        } finally {
            try {
                if (sobj != null) sobj.close();
            } catch (IOException e) {
                // Ignore
            }
        }
    }
}

class GuiChatClient {
    public static void main(String A[]) throws Exception {
        ClientChat cobj = new ClientChat("Client", 400, 300);
        // Start the connection handling logic in a separate thread
        Thread t = new Thread(cobj);
        t.start();
    }
}