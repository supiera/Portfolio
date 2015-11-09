package Report;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class ImageLabelTest extends JFrame implements ActionListener {
	private JPanel panel;
	private JLabel label;
	private JButton button;
	public ImageLabelTest() {
		// TODO Auto-generated constructor stub
		setTitle("�̹��� ���̺�");
		setSize(300, 250);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		panel = new JPanel();
		label = new JLabel("�̹����� ������ �Ʒ� ��ư�� ��������");
		
		button = new JButton("�̹��� ���̺�");
		ImageIcon icon = new ImageIcon("icon.gif");	// imageIcon ��ü ����
		button.setIcon(icon);		//��ư�� imageIcon��ü ����
		button.addActionListener(this);	// ��ư�� �������� 
		panel.add(label);
		panel.add(button);
		add(panel);
		setVisible(true);

	}
	
	public static void main(String args[]){
		ImageLabelTest t = new ImageLabelTest();
	}
	
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		ImageIcon dog = new ImageIcon("dog.gif");
		label.setIcon(dog);			//�̹����� ǥ��
		label.setText(null);		//�ؽ�Ʈ�� null�� ���ش�.
	}

}
