package Report;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class ComboBoxTest extends JFrame implements ActionListener{
	JLabel label;
	
	public ComboBoxTest() {
		// TODO Auto-generated constructor stub
		setTitle("�޺� �ڽ�");
		setSize(300, 200);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		String[] animals = {"dog", "lion", "tiger"};
		JComboBox animalList = new JComboBox(animals);
		animalList.setSelectedIndex(0);
		animalList.addActionListener(this);
		
		label = new JLabel();
		label.setHorizontalAlignment(JLabel.CENTER);
		changePicture(animals[animalList.getSelectedIndex()]);
		add(animalList, BorderLayout.PAGE_START);
		add(label, BorderLayout.PAGE_END);
		setVisible(true);
		
	}
	
	//�޺��ڽ����� �׸��� ���õǸ� ȣ��
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		JComboBox cb = (JComboBox) e.getSource();
		String name = (String) cb.getSelectedItem();
		changePicture(name);
	}
	
	//���õ� �׸� ���� ������ �̹��������� �����ϱ�
	protected void changePicture(String name){
		ImageIcon icon = new ImageIcon(name + ".gif");
		label.setIcon(icon);
		if(icon != null)
			label.setText(null);
		else
			label.setText("�̹����� �߰ߵ��� �ʾҽ��ϴ�.");
	}
	public static void main(String[] args) {
		ComboBoxTest frame = new ComboBoxTest();
	}
}
