package Report;

import javax.swing.*;

import java.awt.event.*;
import javax.swing.tree.*;
import javax.swing.event.*;

public class TreeTest extends JFrame {
	private JTree tree;
	private JLabel label;
	
	public TreeTest() {
		this.setSize(400, 300);
		this.setTitle("Ʈ�� �׽�Ʈ");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		DefaultMutableTreeNode root = new DefaultMutableTreeNode("���� ������");
		DefaultMutableTreeNode child1 = new DefaultMutableTreeNode("����");
		DefaultMutableTreeNode child2 = new DefaultMutableTreeNode("����");
		DefaultMutableTreeNode child3 = new DefaultMutableTreeNode("�ѱ�");
		DefaultMutableTreeNode child4 = new DefaultMutableTreeNode("����");
		DefaultMutableTreeNode child5 = new DefaultMutableTreeNode("����");
		DefaultMutableTreeNode child6 = new DefaultMutableTreeNode("�ܱ�");
		DefaultMutableTreeNode child7 = new DefaultMutableTreeNode("�Ҽ�");
		DefaultMutableTreeNode child8 = new DefaultMutableTreeNode("�߸�");
		
		// ���� ���� ����
		root.add(child1);
		root.add(child2);
		root.add(child7);
		
		child2.add(child3);
		child2.add(child6);
		child3.add(child4);
		child3.add(child5);
		child7.add(child8);
		
		//Ʈ������
		tree = new JTree(root);

		tree.setVisibleRowCount(10);
		tree.addTreeSelectionListener(new TreeListener());

		JPanel panel = new JPanel();
		JScrollPane scroll = new JScrollPane(tree);
		panel.add(scroll);

		label = new JLabel();
		panel.add(label);
		add(panel);

		this.setVisible(true);
	}

	private class TreeListener implements TreeSelectionListener {
		public void valueChanged(TreeSelectionEvent e) {
			DefaultMutableTreeNode node = (DefaultMutableTreeNode) tree
					.getLastSelectedPathComponent();
			if (node == null)
				return;
			String s = (String) node.getUserObject();
			label.setText(s);
		}
	}

	public static void main(String[] args) {
		try {
			UIManager
					.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
		} catch (Exception e) {
			e.printStackTrace();
		}
		new TreeTest();
	}

}
