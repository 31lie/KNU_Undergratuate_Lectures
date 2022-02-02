package application;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseAdapter;
import java.io.IOException;

import java.io.FileWriter;
import java.io.File;

import java.io.BufferedWriter;

import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;

import javax.swing.JLabel;

public class EmotionFrame extends JFrame {

	public void putimage(ImageIcon[] img, int i, JButton[] btn) {
		Image temp = img[i].getImage();
		Image change = temp.getScaledInstance(100, 100, Image.SCALE_SMOOTH);
		ImageIcon tempicon = new ImageIcon(change);
		btn[i].setIcon(tempicon);
	}

	public EmotionFrame(String day) {

		Font font = new Font("�굹�닎 怨좊뵓", Font.PLAIN, 20);

		JFrame frm = new JFrame("Emotion");
		frm.setSize(500, 400);
		frm.setLocationRelativeTo(null);
		frm.getContentPane().setLayout(null);
		frm.setResizable(false);
		frm.getContentPane().setBackground(Color.WHITE);
		JLabel lab = new JLabel();
		lab.setBounds(170, 20, 500, 50);
		lab.setText("Emotion selection");
		lab.setFont(font);
		frm.getContentPane().add(lab);
		JButton[] btn = { new JButton(), new JButton(), new JButton(), new JButton(), new JButton(), new JButton() };

		int x = 75;
		int y = 100;
		for (int i = 0; i < btn.length; i++) {
			btn[i].setBounds(x, y, 100, 100);
			btn[i].setBorderPainted(false);
			btn[i].setContentAreaFilled(false);
			frm.getContentPane().add(btn[i]);
			x += 130;
			if (i % 3 == 2) {
				y += 120;
				x = 75;
			}
		}

		ImageIcon[] img = { new ImageIcon("./data/images/mood/happy.png"), new ImageIcon("./data/images/mood/good.png"),
				new ImageIcon("./data/images/mood/tired.png"), new ImageIcon("./data/images/mood/bad.png"),
				new ImageIcon("./data/images/mood/sad.png"), new ImageIcon("./data/images/mood/sick.png") };

		for (int i = 0; i < img.length; i++) {
			putimage(img, i, btn);
		}

		ImageIcon[] img_r = { new ImageIcon("./data/images/mood/happy_r.png"),
				new ImageIcon("./data/images/mood/good_r.png"), new ImageIcon("./data/images/mood/tired_r.png"),
				new ImageIcon("./data/images/mood/bad_r.png"), new ImageIcon("./data/images/mood/sad_r.png"),
				new ImageIcon("./data/images/mood/sick_r.png") };

		// happy (0)
		btn[0].addActionListener(new ActionListener() {
			Audio mood;

			@Override
			public void actionPerformed(ActionEvent ae) {
				try {
					File file = new File("./data/moodDB/" + day + ".txt");
					BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file));
					if (file.isFile() && file.canWrite()) {
						bufferedWriter.write("0");
						bufferedWriter.close();
					}
				} catch (IOException e) {
					System.out.println(e);
				}

				mood = new Audio("emotion/HAPPY");
				mood.play();

				frm.dispose();
			}
		});
		btn[0].addMouseListener(new MouseListener() {

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mouseExited(MouseEvent e) {
				putimage(img, 0, btn);

			}

			@Override
			public void mouseEntered(MouseEvent e) {
				putimage(img_r, 0, btn);

			}

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub

			}
		});

		// good (1)
		btn[1].addActionListener(new ActionListener() {
			Audio mood;

			@Override
			public void actionPerformed(ActionEvent ae) {
				try {
					File file = new File("./data/moodDB/" + day + ".txt");
					BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file));
					if (file.isFile() && file.canWrite()) {
						bufferedWriter.write("1");
						bufferedWriter.close();
					}
				} catch (IOException e) {
					System.out.println(e);
				}

				mood = new Audio("emotion/GOOD");
				mood.play();

				frm.dispose();
			}
		});
		btn[1].addMouseListener(new MouseListener() {

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mouseExited(MouseEvent e) {
				putimage(img, 1, btn);

			}

			@Override
			public void mouseEntered(MouseEvent e) {
				putimage(img_r, 1, btn);

			}

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub

			}
		});
		// tired (2)
		btn[2].addActionListener(new ActionListener() {
			Audio mood;

			@Override
			public void actionPerformed(ActionEvent ae) {
				try {
					File file = new File("./data/moodDB/" + day + ".txt");
					BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file));
					if (file.isFile() && file.canWrite()) {
						bufferedWriter.write("2");
						bufferedWriter.close();
					}
				} catch (IOException e) {
					System.out.println(e);
				}

				mood = new Audio("emotion/SO_SO");
				mood.play();

				frm.dispose();
			}
		});
		btn[2].addMouseListener(new MouseListener() {

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mouseExited(MouseEvent e) {
				putimage(img, 2, btn);

			}

			@Override
			public void mouseEntered(MouseEvent e) {
				putimage(img_r, 2, btn);

			}

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub

			}
		});

		// bad (3)
		btn[3].addActionListener(new ActionListener() {
			Audio mood;

			@Override
			public void actionPerformed(ActionEvent ae) {
				try {
					File file = new File("./data/moodDB/" + day + ".txt");
					BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file));
					if (file.isFile() && file.canWrite()) {
						bufferedWriter.write("3");
						bufferedWriter.close();
					}
				} catch (IOException e) {
					System.out.println(e);
				}
				mood = new Audio("emotion/BAD");
				mood.play();
				frm.dispose();
			}
		});
		btn[3].addMouseListener(new MouseListener() {

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mouseExited(MouseEvent e) {
				putimage(img, 3, btn);

			}

			@Override
			public void mouseEntered(MouseEvent e) {
				putimage(img_r, 3, btn);

			}

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub

			}
		});
		// sad (4)
		btn[4].addActionListener(new ActionListener() {
			Audio mood;

			@Override
			public void actionPerformed(ActionEvent ae) {
				try {
					File file = new File("./data/moodDB/" + day + ".txt");
					BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file));
					if (file.isFile() && file.canWrite()) {
						bufferedWriter.write("4");
						bufferedWriter.close();
					}
				} catch (IOException e) {
					System.out.println(e);
				}
				mood = new Audio("emotion/BAD");
				mood.play();
				frm.dispose();
			}
		});
		btn[4].addMouseListener(new MouseListener() {

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mouseExited(MouseEvent e) {
				putimage(img, 4, btn);

			}

			@Override
			public void mouseEntered(MouseEvent e) {
				putimage(img_r, 4, btn);

			}

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub

			}
		});
		// sick (5)
		btn[5].addActionListener(new ActionListener() {
			Audio mood;

			@Override
			public void actionPerformed(ActionEvent ae) {
				try {
					File file = new File("./data/moodDB/" + day + ".txt");
					BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file));
					if (file.isFile() && file.canWrite()) {
						bufferedWriter.write("5");
						bufferedWriter.close();
					}
				} catch (IOException e) {
					System.out.println(e);
				}
				mood = new Audio("emotion/SICK");
				mood.play();
				frm.dispose();
			}
		});
		btn[5].addMouseListener(new MouseListener() {

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mouseExited(MouseEvent e) {
				putimage(img, 5, btn);

			}

			@Override
			public void mouseEntered(MouseEvent e) {
				putimage(img_r, 5, btn);

			}

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub

			}
		});

		frm.setVisible(true);
	}

}