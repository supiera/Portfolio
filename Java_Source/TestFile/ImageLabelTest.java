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
		setTitle("이미지 레이블");
		setSize(300, 250);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		panel = new JPanel();
		label = new JLabel("이미지를 보려면 아래 버튼을 누르세요");
		
		button = new JButton("이미지 레이블");
		ImageIcon icon = new ImageIcon("icon.gif");	// imageIcon 객체 생성
		button.setIcon(icon);		//버튼에 imageIcon객체 설정
		button.addActionListener(this);	// 버튼이 눌려지면 
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
		label.setIcon(dog);			//이미지를 표시
		label.setText(null);		//텍스트를 null로 없앤다.
	}

}
