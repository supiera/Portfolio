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
		setTitle("콤보 박스");
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
	
	//콤보박스에서 항목이 선택되면 호출
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		JComboBox cb = (JComboBox) e.getSource();
		String name = (String) cb.getSelectedItem();
		changePicture(name);
	}
	
	//선택된 항목에 따라 적절한 이미지아이콘 선택하기
	protected void changePicture(String name){
		ImageIcon icon = new ImageIcon(name + ".gif");
		label.setIcon(icon);
		if(icon != null)
			label.setText(null);
		else
			label.setText("이미지가 발견되지 않았습니다.");
	}
	public static void main(String[] args) {
		ComboBoxTest frame = new ComboBoxTest();
	}
}
