package Lab10;

/* 2020114658 이윤서
 * 본인은 이 소스파일을 다른 사람의 소스 복사하지 않고 직접 작성하였습니다.
 */

// JPanel that creates a ball when the mouse is pressed.  Ball bounces
// around the JPanel.
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class BallPanel extends JPanel
{

   
   private ExecutorService threadExecutor; // for running Ball runnable
   private JFrame parentWindow; // parent window of JPanel
   private final int MAX_X = 200; // horizontal edge of JPanel
   private final int MAX_Y = 200; // vertical edge of JPanel
   private ArrayList<Ball> balls = new ArrayList<Ball>(20);
   
   
   
   public BallPanel( JFrame window )
   {
      parentWindow = window; // set parent window of JPanel

      // create ExecutorService for running ball runnable
      threadExecutor = Executors.newCachedThreadPool();

      // anonymous inner class handles mouse events
      this.addMouseListener( 
         new MouseAdapter() 
         {
            public void mousePressed( MouseEvent event ) 
            {
               createBall( event ); // delegate call to ball starter
               RepaintTimer timer = new RepaintTimer( parentWindow );
               threadExecutor.execute( timer );
            } // end method mousePressed
         } // end anonymous inner class
      ); // end call to addMouseListener
   } // end BallPanel constructor

   // create a ball if no ball exists and set it in motion
   private void createBall( MouseEvent event )
   {
     
      int x = event.getX();// get x-position 
      int y = event.getY();// get y-position
      
      Ball newball = new Ball(x, y);
      
      this.threadExecutor.execute(newball);
      
      balls.add(newball);
      
     
   } // end method createBall

   // return minimum size of animation
   public Dimension getMinimumSize()
   { 
      return getPreferredSize(); 
   } // end method getMinimumSize

   // return preferred size of animation
   public Dimension getPreferredSize()
   {
      return new Dimension( MAX_X, MAX_Y );
   } // end method getPreferredSize

   // draw ball at current position
   public void paintComponent( Graphics g )
   {
      super.paintComponent( g );
      for (Ball ball : balls) {
    	  	if (ball != null) {
    	  		g.setColor(new Color(ball.red,ball.green,ball.blue));
            g.fillOval(ball.getX(), ball.getY(), 10,10);  
        }
      }
   } // end method paintComponent
} // end class BallPanel