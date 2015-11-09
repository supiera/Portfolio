package Report;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

@SuppressWarnings("serial")
class MyFrame2 extends JFrame{
	private JButton btn;
	private JTextField text, result;
	
	public MyFrame2() {
		// TODO Auto-generated constructor stub
		setSize(300, 130);
		setTitle("���� ����ϱ�");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// ������ ��ü�� �����Ѵ�
		ButtonListener listener = new ButtonListener();
		
		JPanel panel = new JPanel();
		panel.add(new JLabel("���� �Է� : ")); //���̺� ��ü ����
		text = new JTextField(15);	//�÷����� 15�� �ؽ�Ʈ �ʵ� ����
		text.addActionListener(listener);	//�ؽ�Ʈ �ʵ忡 �׼Ǹ����� ���
		panel.add(text);
		
		panel.add(new JLabel("������ �� :"));
		result = new JTextField(15);	//�÷����� 15�� ����� ��Ÿ�� �ؽ�Ʈ �ʵ�
		result.setEditable(false);		//Read Only�� ����
		panel.add(result);
		
		btn = new JButton("OK");
		btn.addActionListener(listener);
		panel.add(btn);
		add(panel);
		setVisible(true);
	}
	
	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			if(e.getSource() == btn || e.getSource() == text){
				String name = text.getText();
				int value = Integer.parseInt(name);
				result.setText(" " + value * value);
				text.requestFocus();
			}
		}
	}
}

public class TextFieldTest {
	public static void main(String[] args){
		new MyFrame2();
	}
}
