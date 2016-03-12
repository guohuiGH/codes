import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class B {

	public String createDir(String dirName) {
		File dir = new File(dirName);
		if (dir.exists()) {
			System.out.println("the dir "+ dirName + "  has exist!");
			return dir.getPath();
		}
		if(dir.mkdirs()) {
			System.out.println("create " + dirName + " sucess!");
			return dir.getPath();
		}else
			System.out.println("fail to create dir " + dirName);
		return null;
	}
	
	public void getFile(File dir, List<String>list) {
		
		final String regex = ".java\\b";
		Pattern pattern = Pattern.compile(regex);
		
		if (!(dir.isDirectory()))
			return;
		File[] lists = dir.listFiles();
		for (File file:lists) {
			if (file.isDirectory())
				getFile(file,list);
			else {
				String info = file.getName();
				Matcher matcher = pattern.matcher(info);
				if (matcher.find()) {
					//System.out.println(file.getPath());
					list.add(file.getPath());
				}
			}
		}
	}
	
	public void moveFile(List<String>list, String destPath) throws IOException {
		for (String s:list) {
			File file = new File(s);
			try {
				String name = file.getName();
				String newName = name.substring(0, name.length()-3);
				FileInputStream fileInputStream = new FileInputStream(s);
				FileOutputStream fileOutputStream = new FileOutputStream(destPath + newName);
				byte[] buff = new byte[1024];
				int len = fileInputStream.read(buff);
				while(len!=-1) {
					fileOutputStream.write(buff);
					len = fileInputStream.read(buff);
				}
				fileInputStream.close();
				fileOutputStream.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}
	

	public static void main (String argv[]) throws IOException {
		B b = new B();
		String destPath = b.createDir("java");
		if (destPath != null) {
			List<String> list = new ArrayList<String>();
			b.getFile(new File("C:\\Users\\»Ô\\workspace\\0331\\src\\"),list);
			b.moveFile(list, destPath + "\\");
		}
			
	}
}
