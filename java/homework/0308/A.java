import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

@SuppressWarnings("serial")
class Student implements Serializable{
	String id,name, birthday;
	public Student(String id, String name, String birthday) {
		// TODO Auto-generated constructor stub
		this.id = id;
		this.name = name;
		this.birthday = birthday;
	}
	//cover the method equals
	public boolean equals(Object ob) {
		if (this == ob)
			return true;
		if (! (ob instanceof Student))
			return false;
		Student student = (Student)ob;
		if (this.id.equals(student.id) && this.name.equals(student.name) && this.birthday.equals(student.birthday))
			return true;
		return false;
	}
}

public class A {
	
	//add the Object 
	protected void addStudent(String filePath, Student student){
		ObjectOutputStream objectOutputStream;
		try {
			boolean isExistFile = false;
			File file = new File(filePath);
			if (file.exists())
				isExistFile = true;
			//write the file from the end of file
			FileOutputStream fileOutputStream = new FileOutputStream(filePath, true);
			objectOutputStream = new ObjectOutputStream(fileOutputStream);
			long position = 0;
			//delete the header(4byte)
			if (isExistFile && fileOutputStream.getChannel().position() > 4) {
				position = fileOutputStream.getChannel().position()-4;
				fileOutputStream.getChannel().truncate(position);
			}
			objectOutputStream.writeObject(student);
			objectOutputStream.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	//delete the message
	@SuppressWarnings("resource")
	protected Student deleteStudent (String filePath, Student student) throws ClassNotFoundException,NullPointerException {
		if (!searchStudent(filePath, student))
			throw new NullPointerException("please check your file! No such student");
		Student s = null;
		try {
			FileInputStream fileInputStream = new FileInputStream(filePath);
			List<Student>list = new ArrayList<Student>();
			ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
			while (fileInputStream.available()>0) {
				Student student2 = (Student)objectInputStream.readObject();
				if (student2 != null && student2.equals(student)) {
					s = student2;
					continue;
				}
				else
					list.add(student2);
			}
			//clear the file and add new message
			FileOutputStream fileOutputStream = new FileOutputStream(filePath);
			ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
			objectOutputStream.writeObject(null);;
			fileOutputStream.close();
			for(Student st:list) {
				if (st != null)
					addStudent(filePath, st);
			}
			fileInputStream.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return s;
	}
	
	//change the message
	protected void changeStudent(String filePath, Student oldStudent, Student newStudent) throws ClassNotFoundException, NullPointerException {
		if (searchStudent(filePath,	 oldStudent))
			deleteStudent(filePath, oldStudent);
		addStudent(filePath, newStudent);
		
	}
	
	//search Student
	@SuppressWarnings("resource")
	protected boolean searchStudent(String filePath, Student student) throws ClassNotFoundException {
		try {
			FileInputStream fileInputStream = new FileInputStream(filePath);
			ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
			while (fileInputStream.available() > 0) {
				Student student2 = (Student)objectInputStream.readObject();
				if (student2 != null && student2.equals(student))
					return true;
			}
			fileInputStream.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return false;
	}
	
	protected List<Student> getStudent(String filePath) throws ClassNotFoundException {
		List<Student> list = new ArrayList<Student>();
		try {
			FileInputStream fileInputStream = new FileInputStream(filePath);
			ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
			
			while (fileInputStream.available()>0) {
				Student student = (Student)objectInputStream.readObject();
				if (student!=null)
				list.add(student);
			}
			fileInputStream.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO: handle exception
			e.printStackTrace();
		}
		
		return list;
	}
	
	// get the student message by regular
	protected List<Student> getStudentByRegular(String filePath, String number, String month) throws ClassNotFoundException {
		List<Student> list = getStudent(filePath);
		
		List<Student> list2 = new ArrayList<Student>();
		String regexId = number + "\\b";
		Pattern patternId = Pattern.compile(regexId);
		String regexMonth = "-" + month + "-";
		Pattern patternMonth = Pattern.compile(regexMonth);
		for (Student li:list) {
			if (li != null) {
				Matcher matcherId = patternId.matcher(li.id);
				Matcher matcherBirthday = patternMonth.matcher(li.birthday);
				if (matcherId.find() && matcherBirthday.find())
					list2.add(li);
			}	
		}
		return list2;
	}
	
	private void printStudent(List<Student>list) {
		for (Student li:list) {
			String msg = li.id + " " + li.name + " " + li.birthday;
			System.out.println(msg);
		}
	}
	
	public static void  main(String argv[]) throws FileNotFoundException, IOException, ClassNotFoundException {
		
		A a = new A();
		String filePath = "student.obj";
		
		a.addStudent(filePath, new Student("128", "a", "2016-03-11"));
		a.addStudent(filePath, new Student("127", "b", "2016-03-10"));
		a.addStudent(filePath, new Student("118", "c", "2016-03-12"));
		a.addStudent(filePath, new Student("108", "e", "2016-03-11"));
		System.out.println("this is test for add:");
		List<Student> list = a.getStudent(filePath);
		a.printStudent(list);
		System.out.println("this is test for delete(118,c,2016-03-12):");
		a.deleteStudent(filePath, new Student("118", "c", "2016-03-12"));
		List<Student> list2 = a.getStudent(filePath);
		a.printStudent(list2);
		System.out.println("this is test for search(128,f,2016-03-11):");
		
		if (a.searchStudent(filePath, new Student("128", "f", "2016-03-11")))
			System.out.println("i find it!");
		else
			System.out.println("no message for this user");
		System.out.println("this is test for change(128,a,2016-03-11) to (128,f,2016-03-11)");
		a.changeStudent(filePath, new Student("128", "a", "2016-03-11"), new Student("128", "f", "2016-03-11"));
		if (a.searchStudent(filePath, new Student("128", "f", "2016-03-11")))
			System.out.println("i find it!");
		else
			System.out.println("no message for this user");
		System.out.println("this is test to search by regular");
		List<Student> list3 = a.getStudentByRegular(filePath, "8", "03");
		a.printStudent(list3);
	}
	
}
