package Report;

import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class FileChooserTest extends JFrame implements ActionListener{
	JButton openButton, saveButton;
	JFileChooser fc;

	public FileChooserTest(){
		setTitle("���� ���ñ� �׽�Ʈ");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(300, 200);

		fc = new JFileChooser();

		JLabel label = new JLabel("���� ���ñ� ������Ʈ �׽�Ʈ�Դϴ�.");
		openButton = new JButton("���� ����");
		openButton.addActionListener(this);

		saveButton = new JButton("���� ����");
		saveButton.addActionListener(this);

		JPanel panel = new JPanel();
		panel.add(label);
		panel.add(openButton);
		panel.add(saveButton);
		add(panel);
		setVisible(true);
	}

	public void actionPerformed(ActionEvent e){
		if (e.getSource() == openButton) {
			int returnVal = fc.showOpenDialog(this);
			
			if (returnVal == JFileChooser.APPROVE_OPTION) {}
			else {}
		}else if (e.getSource() == saveButton){
			int returnVal = fc.showSaveDialog(this);
			if (returnVal == JFileChooser.APPROVE_OPTION) {} 
			else{}
		}
	}

	public static void main(String[] args){
		FileChooserTest frame = new FileChooserTest();
	}
}
