import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;

public class Calculator implements ActionListener {
    Boolean isOperator = false;
    Boolean isMultiplication = false;
    Boolean isAddition = false;
    Boolean isSubstraction = false;
    Boolean isDivision = false;
    Boolean isPoint = true;

    float oldValue;
    float nexValue;
    String oldString;
    String newString;

    JLabel display = new JLabel("");

    JButton sevenButton = new JButton("7");
    JButton eightButton = new JButton("8");
    JButton nineButton = new JButton("9");
    JButton fourButton = new JButton("4");
    JButton fiveButton = new JButton("5");
    JButton sixButton = new JButton("6");
    JButton oneButton = new JButton("1");
    JButton twoButton = new JButton("2");
    JButton threeButton = new JButton("3");
    JButton DzeroButton = new JButton("00");
    JButton zeroButton = new JButton("0");
    JButton pointButton = new JButton(".");
    JButton divisionButton = new JButton("/");
    JButton multiButton = new JButton("x");
    JButton additionButton = new JButton("+");
    JButton substractionButton = new JButton("-");
    JButton clearButton = new JButton("C");
    JButton equalButton = new JButton("=");

    Calculator() {
        // FRAME SETUP
        JFrame jf = new JFrame("Calculator");
        jf.setBounds(400, 100, 382, 520);
        jf.setBackground(Color.black);
        jf.getContentPane().setBackground(Color.black);

        // DISPLAY
        display.setBounds(4, 30, 373, 93);
        display.setBackground(Color.green);
        display.setForeground(Color.black);
        display.setOpaque(true);
        display.setHorizontalAlignment(SwingConstants.RIGHT);
        display.setBorder(new EmptyBorder(0, 10, 0, 10));
        display.setFont(new Font("Arial", Font.BOLD, 22));

        jf.add(display);

        // BUTTONS
        // row 1
        sevenButton.setBounds(4, 130, 120, 50);
        sevenButton.setFont(new Font("Arial", Font.PLAIN, 20));
        sevenButton.setBackground(Color.darkGray);
        sevenButton.setBorderPainted(false);
        sevenButton.setFocusPainted(false);
        sevenButton.setForeground(Color.lightGray);
        sevenButton.addActionListener(this);
        jf.add(sevenButton);

        eightButton.setBounds(131, 130, 120, 50);
        eightButton.setFont(new Font("Arial", Font.PLAIN, 20));
        eightButton.setBackground(Color.darkGray);
        eightButton.setBorderPainted(false);
        eightButton.setFocusPainted(false);
        eightButton.setForeground(Color.lightGray);
        eightButton.addActionListener(this);

        jf.add(eightButton);

        nineButton.setBounds(258, 130, 120, 50);
        nineButton.setFont(new Font("Arial", Font.PLAIN, 20));
        nineButton.setBackground(Color.darkGray);
        nineButton.setBorderPainted(false);
        nineButton.setFocusPainted(false);
        nineButton.setForeground(Color.lightGray);
        nineButton.addActionListener(this);

        jf.add(nineButton);

        // row 2
        fourButton.setBounds(4, 190, 120, 50);
        fourButton.setFont(new Font("Arial", Font.PLAIN, 20));
        fourButton.setBackground(Color.darkGray);
        fourButton.setBorderPainted(false);
        fourButton.setFocusPainted(false);
        fourButton.setForeground(Color.lightGray);
        fourButton.addActionListener(this);

        jf.add(fourButton);

        fiveButton.setBounds(131, 190, 120, 50);
        fiveButton.setFont(new Font("Arial", Font.PLAIN, 20));
        fiveButton.setBackground(Color.darkGray);
        fiveButton.setBorderPainted(false);
        fiveButton.setFocusPainted(false);
        fiveButton.setForeground(Color.lightGray);
        fiveButton.addActionListener(this);

        jf.add(fiveButton);

        sixButton.setBounds(258, 190, 120, 50);
        sixButton.setFont(new Font("Arial", Font.PLAIN, 20));
        sixButton.setBackground(Color.darkGray);
        sixButton.setBorderPainted(false);
        sixButton.setFocusPainted(false);
        sixButton.setForeground(Color.lightGray);
        sixButton.addActionListener(this);

        jf.add(sixButton);

        // row 3
        oneButton.setBounds(4, 250, 120, 50);
        oneButton.setFont(new Font("Arial", Font.PLAIN, 20));
        oneButton.setBackground(Color.darkGray);
        oneButton.setBorderPainted(false);
        oneButton.setFocusPainted(false);
        oneButton.setForeground(Color.lightGray);
        oneButton.addActionListener(this);

        jf.add(oneButton);

        twoButton.setBounds(131, 250, 120, 50);
        twoButton.setFont(new Font("Arial", Font.PLAIN, 20));
        twoButton.setBackground(Color.darkGray);
        twoButton.setBorderPainted(false);
        twoButton.setFocusPainted(false);
        twoButton.setForeground(Color.lightGray);
        twoButton.addActionListener(this);

        jf.add(twoButton);

        threeButton.setBounds(258, 250, 120, 50);
        threeButton.setFont(new Font("Arial", Font.PLAIN, 20));
        threeButton.setBackground(Color.darkGray);
        threeButton.setBorderPainted(false);
        threeButton.setFocusPainted(false);
        threeButton.setForeground(Color.lightGray);
        threeButton.addActionListener(this);

        jf.add(threeButton);

        // row 4
        DzeroButton.setBounds(4, 310, 120, 50);
        DzeroButton.setFont(new Font("Arial", Font.PLAIN, 20));
        DzeroButton.setBackground(Color.darkGray);
        DzeroButton.setBorderPainted(false);
        DzeroButton.setFocusPainted(false);
        DzeroButton.setForeground(Color.lightGray);
        DzeroButton.addActionListener(this);

        jf.add(DzeroButton);

        zeroButton.setBounds(131, 310, 120, 50);
        zeroButton.setFont(new Font("Arial", Font.PLAIN, 20));
        zeroButton.setBackground(Color.darkGray);
        zeroButton.setBorderPainted(false);
        zeroButton.setFocusPainted(false);
        zeroButton.setForeground(Color.lightGray);
        zeroButton.addActionListener(this);

        jf.add(zeroButton);

        pointButton.setBounds(258, 310, 120, 50);
        pointButton.setFont(new Font("Arial", Font.PLAIN, 20));
        pointButton.setBackground(Color.darkGray);
        pointButton.setBorderPainted(false);
        pointButton.setFocusPainted(false);
        pointButton.setForeground(Color.lightGray);
        pointButton.addActionListener(this);

        jf.add(pointButton);

        // row 5
        divisionButton.setBounds(4, 370, 120, 50);
        divisionButton.setFont(new Font("Arial", Font.PLAIN, 20));
        divisionButton.setBackground(Color.darkGray);
        divisionButton.setBorderPainted(false);
        divisionButton.setFocusPainted(false);
        divisionButton.setForeground(Color.lightGray);
        divisionButton.addActionListener(this);
        jf.add(divisionButton);

        multiButton.setBounds(131, 370, 120, 50);
        multiButton.setFont(new Font("Arial", Font.PLAIN, 20));
        multiButton.setBackground(Color.darkGray);
        multiButton.setBorderPainted(false);
        multiButton.setFocusPainted(false);
        multiButton.setForeground(Color.lightGray);
        multiButton.addActionListener(this);

        jf.add(multiButton);

        additionButton.setBounds(258, 370, 120, 50);
        additionButton.setFont(new Font("Arial", Font.PLAIN, 20));
        additionButton.setBackground(Color.darkGray);
        additionButton.setBorderPainted(false);
        additionButton.setFocusPainted(false);
        additionButton.setForeground(Color.lightGray);
        additionButton.addActionListener(this);

        jf.add(additionButton);

        // row 6
        substractionButton.setBounds(4, 430, 120, 50);
        substractionButton.setFont(new Font("Arial", Font.PLAIN, 20));
        substractionButton.setBackground(Color.darkGray);
        substractionButton.setBorderPainted(false);
        substractionButton.setFocusPainted(false);
        substractionButton.setForeground(Color.lightGray);
        substractionButton.addActionListener(this);

        jf.add(substractionButton);

        clearButton.setBounds(131, 430, 120, 50);
        clearButton.setFont(new Font("Arial", Font.PLAIN, 20));
        clearButton.setBackground(Color.darkGray);
        clearButton.setBorderPainted(false);
        clearButton.setFocusPainted(false);
        clearButton.setForeground(Color.lightGray);
        clearButton.addActionListener(this);
        jf.add(clearButton);

        equalButton.setBounds(258, 430, 120, 50);
        equalButton.setFont(new Font("Arial", Font.PLAIN, 20));
        equalButton.setBackground(Color.darkGray);
        equalButton.setBorderPainted(false);
        equalButton.setFocusPainted(false);
        equalButton.setForeground(Color.lightGray);
        equalButton.addActionListener(this);

        jf.add(equalButton);

        jf.setLayout(null);
        jf.setVisible(true);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        System.out.println("claculator");
        new Calculator();

    }

    public void actionPerformed(ActionEvent e) {
        // number section
        if (e.getSource() == sevenButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("7");
                isOperator = false;
            } else {
                display.setText(display.getText() + "7");
            }
        } else if (e.getSource() == eightButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("8");
                isOperator = false;
            } else {
                display.setText(display.getText() + "8");
            }
        } else if (e.getSource() == nineButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("9");
                isOperator = false;
            } else {
                display.setText(display.getText() + "9");
            }
        } else if (e.getSource() == fourButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("4");
                isOperator = false;
            } else {
                display.setText(display.getText() + "4");
            }
        } else if (e.getSource() == fiveButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("5");
                isOperator = false;
            } else {
                display.setText(display.getText() + "5");
            }
        } else if (e.getSource() == sixButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("6");
                isOperator = false;
            } else {
                display.setText(display.getText() + "6");
            }
        } else if (e.getSource() == oneButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("1");
                isOperator = false;
            } else {
                display.setText(display.getText() + "1");
            }
        } else if (e.getSource() == twoButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("2");
                isOperator = false;
            } else {
                display.setText(display.getText() + "2");
            }
        } else if (e.getSource() == threeButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("3");
                isOperator = false;
            } else {
                display.setText(display.getText() + "3");
            }
        } else if (e.getSource() == pointButton) {
            if (isPoint) {
                display.setText(display.getText() + ".");
                isPoint = false;
            }
        } else if (e.getSource() == zeroButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("0");
                isOperator = false;
            } else {
                display.setText(display.getText() + "0");

            }
        } else if (e.getSource() == DzeroButton) {
            if (isOperator) {
                oldString = display.getText();
                display.setText("00");
                isOperator = false;
            } else {
                display.setText(display.getText() + "00");

            }
        } else if (e.getSource() == clearButton) {
            display.setText("");
        }

        // operator section
        if (e.getSource() == divisionButton) {
            isOperator = true;
            isDivision = true;
            isPoint = true;
        } else if (e.getSource() == multiButton) {
            isOperator = true;
            isMultiplication = true;
            isPoint = true;
        } else if (e.getSource() == additionButton) {
            isOperator = true;
            isAddition = true;
            isPoint = true;
        } else if (e.getSource() == substractionButton) {
            isOperator = true;
            isSubstraction = true;
            isPoint = true;
        } else if (e.getSource() == equalButton) {
            newString = display.getText();
            if (isDivision) {
                display.setText("" + (Float.parseFloat(oldString) / Float.parseFloat(newString)));
                isDivision = false;
            } else if (isMultiplication) {
                display.setText("" + (Float.parseFloat(oldString) * Float.parseFloat(newString)));
                isMultiplication = false;
            } else if (isAddition) {
                display.setText("" + (Float.parseFloat(oldString) + Float.parseFloat(newString)));
                isAddition = false;
            } else if (isSubstraction) {
                display.setText("" + (Float.parseFloat(oldString) - Float.parseFloat(newString)));
                isSubstraction = false;
            }
        }

        throw new UnsupportedOperationException("Unimplemented method 'actionPerformed'");
    }
}
