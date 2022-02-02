package application;

import java.awt.EventQueue;
import java.io.IOException;

public class App {
	/* Launch the application */
	public static void main(String[] args) throws IOException {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Audio kaily = new Audio("Kaily");
					kaily.play();
					Main window = new Main();
					window.frame.setVisible(true);
					window.frame.setLocationRelativeTo(null);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}