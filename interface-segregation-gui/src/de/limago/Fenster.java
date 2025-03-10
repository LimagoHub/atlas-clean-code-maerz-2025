package de.limago;

import java.awt.*;
import java.awt.event.*;


public class Fenster extends Frame  {


    public Fenster()  {

        setSize(300, 300);
        Button button = new Button("Drück mich");
        button.addActionListener(e->ausgabe());
        add(button);
        addWindowListener(new MyWindowListener());
    }

    private void ausgabe() {
        System.out.println("Button wurde gedrueckt");
    }

    private void beenden() {
        dispose();
    }

    public static void main(String[] args) {

        new Fenster().setVisible(true);
    }

    /*private class ButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            ausgabe();
        }
    }*/

   private class MyWindowListener extends WindowAdapter {
       @Override
       public void windowClosing(final WindowEvent e) {
           beenden();
       }
   }
}
