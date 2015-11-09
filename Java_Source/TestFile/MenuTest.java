package Report;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MenuTest extends JFrame implements ActionListener, ItemListener{
	private JMenuBar menuBar;
	private JMenu menu, submenu;
	private JMenuItem menuItem1, menuItem2;
	private JMenuItem sbMenuItem1, sbMenuItem2;
	private JRadioButtonMenuItem rbMenuItem1, rbMenuItem2;
	private JCheckBoxMenuItem cbMenuItem1, cbMenuItem2;

	public MenuTest(){
		menuBar = new JMenuBar();

		menu = new JMenu("첫번째 메뉴");
		menu.setMnemonic(KeyEvent.VK_F);
		menuBar.add(menu);

		menuItem1 = new JMenuItem("메뉴 항목 1", KeyEvent.VK_1);
		menuItem1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_M, ActionEvent.ALT_MASK));
		menuItem1.addActionListener(this);
		menu.add(menuItem1);

		ImageIcon icon = new ImageIcon("icon.gif");
		menuItem2 = new JMenuItem("메뉴 항목 2", icon);
		menu.add(menuItem2);

		menu.addSeparator();
		ButtonGroup group = new ButtonGroup();

		rbMenuItem1 = new JRadioButtonMenuItem("라디오 버튼 메뉴 항목 1");
		rbMenuItem1.setSelected(true);
		group.add(rbMenuItem1);
		menu.add(rbMenuItem1);

		rbMenuItem2 = new JRadioButtonMenuItem("라디오 버튼 메뉴 항목 2");
		group.add(rbMenuItem2);
		menu.add(rbMenuItem2);

		menu.addSeparator();
		cbMenuItem1 = new JCheckBoxMenuItem("체크 박스 메뉴 항목 1");
		cbMenuItem1.addItemListener(this);
		menu.add(cbMenuItem1);

		cbMenuItem2 = new JCheckBoxMenuItem("체크 박스 메뉴 항목 2");
		menu.add(cbMenuItem2);

		menu.addSeparator();
		submenu = new JMenu("서브 메뉴");
		submenu.setMnemonic(KeyEvent.VK_S);

		sbMenuItem1 = new JMenuItem("서브 메뉴 항목 1");
		sbMenuItem1.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_1, ActionEvent.ALT_MASK));
		submenu.add(sbMenuItem1);

		sbMenuItem2 = new JMenuItem("서브 메뉴 항목 2");
		submenu.add(sbMenuItem2);
		menu.add(submenu);
		
		menu = new JMenu("두번째 메뉴");
		menu.setMnemonic(KeyEvent.VK_S);
		menuBar.add(menu);

		// 메뉴바를 프레임에 부착한다.
		setJMenuBar(menuBar);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e){
		if (e.getSource() == menuItem1)
			JOptionPane.showMessageDialog(this, "메뉴 항목 1이 선택되었습니다.");
	}

	public void itemStateChanged(ItemEvent e) {
		if (e.getSource() == cbMenuItem1)
			JOptionPane.showMessageDialog(this, "체크 박스 메뉴 항목 1이 변경되었습니다.");
	}

	public static void main(String args[]) {
		MenuTest f = new MenuTest();
		f.setSize(500, 200);
		f.setVisible(true);
	}
}
