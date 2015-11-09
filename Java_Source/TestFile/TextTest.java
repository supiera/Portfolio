package Report;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.ParseException;

import javax.swing.JFormattedTextField;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.text.MaskFormatter;

class MyFrame5 extends JFrame implements ActionListener{
	protected JTextField id;
	protected JPasswordField password;
	protected JFormattedTextField date;
	protected JTextArea textArea;
	
	public MyFrame5() throws ParseException {
		// TODO Auto-generated constructor stub
		super("MY Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		panel.setLayout(new GridLayout(3, 2));
		
		id = new JTextField(30);
		id.addActionListener(this);
		panel.add(new JLabel("ID:"));
		panel.add(id);
		
		password = new JPasswordField(30);
		password.addActionListener(this);
		panel.add(new JLabel("PASSWORD:"));
		panel.add(password);
		
		MaskFormatter mf = new MaskFormatter("####.##.##");
		mf.setPlaceholderCharacter('_');
		date = new JFormattedTextField(mf);
		date.addActionListener(this);
		panel.add(new JLabel("DATE:"));
		panel.add(date);
		
		textArea = new JTextArea(10, 30);
		textArea.setEditable(false);
		add(panel, BorderLayout.NORTH);
		add(textArea, BorderLayout.CENTER);
		pack();
		setVisible(true);
	}
	
	@SuppressWarnings("deprecation")
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource() == id || e.getSource() == password || e.getSource() == date){
			String text = "id = " + id.getText() + " password = " + password.getText() 
					+ " date = " + date.getText();
			textArea.append(text + "\n");
			id.selectAll();
			password.selectAll();
			date.selectAll();
			textArea.setCaretPosition(textArea.getDocument().getLength());
		}
	}
}

public class TextTest {
	public static void main(String[] args) throws ParseException {
		new MyFrame5();
	}
}
