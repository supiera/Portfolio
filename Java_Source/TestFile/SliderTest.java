package Report;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.applet.Applet;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class SliderTest extends JFrame implements ChangeListener {
	static final int INIT_VALUE = 15;
	private JSlider slider;
	private JButton button;

	public SliderTest() {
		JPanel panel;
		setTitle("슬라이더 테스트");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		panel = new JPanel();
		JLabel label = new JLabel("슬라이더를 움직여보세요", JLabel.CENTER);
		label.setAlignmentX(Component.CENTER_ALIGNMENT);
		panel.add(label);

		slider = new JSlider(0, 30, INIT_VALUE);
		slider.setMajorTickSpacing(10); 
		slider.setMinorTickSpacing(1); 
		
		slider.setPaintTicks(true); // 눈금을 표시한다.
		slider.setPaintLabels(true); // 값을 레이블로 표시한다.
		slider.addChangeListener(this);
		panel.add(slider);
		
		//이미지 아이콘 생성
		button = new JButton("");
		ImageIcon icon = new ImageIcon("dog.gif");
		button.setIcon(icon);
		button.setSize(INIT_VALUE * 10, INIT_VALUE * 10);
		panel.add(button);
		add(panel);
		setSize(300, 300);
		setVisible(true);
	}
	
	//슬라이더 값이 변경되면 읽은 값으로 버튼의 크기 변경
	public void stateChanged(ChangeEvent e) {
		JSlider source = (JSlider) e.getSource();
		if (!source.getValueIsAdjusting()) {
			int value = (int) source.getValue();
			button.setSize(value * 10, value * 10);
		}
	}

	public static void main(String[] args) {
		new SliderTest();
	}
}
