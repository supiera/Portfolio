package Report;

import java.awt.GridLayout;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.ImageIcon;
import javax.swing.JCheckBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class CheckBoxTest extends JPanel implements ItemListener{
	
	JCheckBox[] btns = new JCheckBox[3];	//��ư
	String[] fruits = {"apple", "grape", "orange"};
	JLabel[] pictureLabel = new JLabel[3];
	ImageIcon[] icon = new ImageIcon[3];
	
	public CheckBoxTest() {
		// TODO Auto-generated constructor stub
		super(new GridLayout(0,4));
		
		//üũ �ڽ��� ����
		for(int i = 0; i<3; i++){
			btns[i] = new JCheckBox(fruits[i]);
			btns[i].addItemListener(this);		//üũ�ڽ��� ������ �����ʸ� ���
			pictureLabel[i] = new JLabel(fruits[i] + ".gif");
			icon[i] = new ImageIcon(fruits[i] + ".gif");
		}
		
		JPanel checkPanel = new JPanel(new GridLayout(0, 1));
		for(int i = 0; i<3; i++)
			checkPanel.add(btns[i]);
		
		add(checkPanel);
		add(pictureLabel[0]);	//apple
		add(pictureLabel[1]);	//grape
		add(pictureLabel[2]);	//orange
	}
	
	@Override
	public void itemStateChanged(ItemEvent e) {
		// TODO Auto-generated method stub
		ImageIcon image = null;
		Object source = e.getItemSelectable();		//���õ� üũ�ڽ����� ���´�.
		for(int i = 0; i<3; i++){
			if(source == btns[i]){
				if(e.getStateChange() == ItemEvent.DESELECTED)		//üũ�ڽ��� �����Ǿ�����
					pictureLabel[i].setIcon(null);		//�������� ���ش�
				else		//üũ�ڽ��� �Ǿ�������
					pictureLabel[i].setIcon(icon[i]);		//�������� �����ش�
			}
		}
	}
	
	public static void main(String args[]){
		JFrame frame = new JFrame("CheckBoxDemo");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JComponent newContentPane = new CheckBoxTest();
		newContentPane.setOpaque(true);
		frame.setContentPane(newContentPane);
		frame.setSize(500, 200);
		frame.setVisible(true);
	}

}
