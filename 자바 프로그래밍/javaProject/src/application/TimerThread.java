package application;

import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.JLabel;

public class TimerThread extends Thread {
	JLabel timerLabel;

	public TimerThread(JLabel timerLabel) {
		this.timerLabel = timerLabel;
	}

	// Calculate current clock
	public void run() {
		String sday = null;
		String _clock = null;
		SimpleDateFormat format1 = new SimpleDateFormat("HH : mm");
		while (true) {
			_clock = format1.format(new Date());
			timerLabel.setText(_clock);
			try {
				Thread.sleep(1000);
			} catch (Exception e) {
			}
		}
	}
}