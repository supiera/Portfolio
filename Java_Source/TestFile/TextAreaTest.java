package Report;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextField;

class MyFrame4 extends JFrame implements ActionListener{
	protected JTextField textField;
	protected JTextArea textArea;
	
	public MyFrame4() {
		// TODO Auto-generated constructor stub
		setTitle("Text Area Test");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		textField = new JTextField(30);
		textField.addActionListener(this);
		
		textArea = new JTextArea(10, 30);
		textArea.setEditable(false);
		
		add(textField, BorderLayout.NORTH);
		add(textArea, BorderLayout.CENTER);
		
		pack();
		setVisible(true);
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		String text = textField.getText();
		textArea.append(text + "\n");
		textField.selectAll();
		textArea.setCaretPosition(textArea.getDocument().getLength());
	}
	
}

public class TextAreaTest {
	public static void main(String[] args) {
		new MyFrame4();
	}
}
