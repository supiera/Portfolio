package Report;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

@SuppressWarnings("serial")
class MyFrame extends JFrame implements ActionListener{
	private JRadioButton small, medium, large;
	private JLabel text;
	private JPanel topPanel, sizePanel, resultPanel;
	
	public MyFrame() {
		// TODO Auto-generated constructor stub
		setTitle("라디오 버튼 테스트");
		setSize(300, 150);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		topPanel = new JPanel();
		JLabel label = new JLabel("어떤 크기의 커피를 주문하시겠습니까?");
		topPanel.add(label);
		add(topPanel, BorderLayout.NORTH);
		
		// 라디오 버튼을 생성한다.
		sizePanel = new JPanel();
		small = new JRadioButton("Small Size");
		medium = new JRadioButton("Medium Size");
		large = new JRadioButton("Large Size");
		
		//그룹생성
		ButtonGroup size = new ButtonGroup();
		// 그룹에 라디오 버튼 추가
		size.add(small);
		size.add(medium);
		size.add(large);
		//버튼에 액션리스터를 등록
		small.addActionListener(this);
		medium.addActionListener(this);
		large.addActionListener(this);
		//버튼 그룹을 생성, 라디오 버튼 추가
		sizePanel.add(small);
		sizePanel.add(medium);
		sizePanel.add(large);
		add(sizePanel, BorderLayout.CENTER);
		
		resultPanel = new JPanel();
		text = new JLabel("크기가 선택되지 않았습니다.");
		text.setForeground(Color.red);
		resultPanel.add(text);
		add(resultPanel, BorderLayout.SOUTH);
		setVisible(true);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource() == small)
			text.setText("Small Size가 선택되었습니다.");
		if(e.getSource() == medium)
			text.setText("Medium Size가 선택되었습니다.");
		if(e.getSource() == large)
			text.setText("Large Size가 선택되었습니다.");
	}
	
}

@SuppressWarnings("serial")
public class RadioButtonTest extends JFrame{
	public static void main(String[] args){
		new MyFrame();
	}
}
