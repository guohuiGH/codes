package exercise;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;


public class Books {
	static final String DATABASE_URL = "jdbc:mysql://localhost:3306/books?useSSL=false";
	private Connection connection = null;
	private Statement statement = null;
	private ResultSet resultSet = null;
	
	private void connenctMysql() {
		
		try {
			
			Class.forName("com.mysql.jdbc.Driver");
			connection = DriverManager.getConnection(DATABASE_URL,"root","root");
			statement = connection.createStatement();
			//String s = "drop table Author;";
			String s = "create table Author(id char(20), firstName varchar(64), lastName varchar(64), primary key(id));";
			int result = statement.executeUpdate(s);
			
			if (result != -1) {
				System.out.println("create table Author success!");
			}
			
		} catch (SQLException e) {
			// TODO: handle exception
		} catch (Exception e) {
			// TODO: handle exception
		}
	}
	
	private void printfTable() {
		String sql = "select * from Author";
		try {
			resultSet = statement.executeQuery(sql);
			ResultSetMetaData metaData = resultSet.getMetaData();
			int columns = metaData.getColumnCount();
			System.out.println("Author table of Bools Database:\n");
			
			for (int i = 1; i < columns; i++) 
				System.out.printf("%-8s\t", metaData.getColumnName(i));
			System.out.println();
			while (resultSet.next()) {
				for (int i = 1; i <= columns; i++)
					System.out.printf("%-8s\t", resultSet.getObject(i));
				System.out.println();
			}
		} catch (Exception e) {
			// TODO: handle exception
		}	
	}
	
	private void printfTable(String sql) {
		
		try {
			resultSet = statement.executeQuery(sql);
			ResultSetMetaData metaData = resultSet.getMetaData();
			int columns = metaData.getColumnCount();
			System.out.println("Author table of Bools Database:\n");
			
			for (int i = 1; i < columns; i++) 
				System.out.printf("%-8s\t", metaData.getColumnName(i));
			System.out.println();
			while (resultSet.next()) {
				for (int i = 1; i <= columns; i++)
					System.out.printf("%-8s\t", resultSet.getObject(i));
				System.out.println();
			}
		} catch (Exception e) {
			// TODO: handle exception
		}	
	}
	
	private void insertInfo(String id, String firstName, String lastName) {
		String sql = "insert into Author(id, firstName,lastName) values('" + id + "', '" + firstName + "', '" + lastName + "')";
		try {
			statement.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			System.out.println("something wrong in insert table!");
			e.printStackTrace();
		}
 	}
	
	private void updateInfo(String id, String firstName, String lastName) {
		String sql;
		if (firstName == null && lastName == null)
			return;
		
		if (firstName == null )
			sql = "update Author set lastName='"+lastName + "' where id= '" + id+ "'";
		else if (lastName == null) {
			sql = "update Author set firstName='"+firstName + "' where id= '" + id+ "'";
		}else {
			sql = "update Author set firstName='"+lastName + "',lastName='" + lastName+ "' where id= '" + id+ "'";
		}
		try {
			statement.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			System.out.println("something wrong in update table!");
			e.printStackTrace();
		}
	}
	
	private void searchInfo(String sql) {
		printfTable(sql);
	}
	
	private void deleteInfo(String id) {
		String sql = "delete from Author where id='"+ id + "'";
		try {
			statement.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			System.out.println("something wrong in delete table!");
			e.printStackTrace();
		}
	}
	public static void main (String[] argv) {
		Books books = new Books();
		books.connenctMysql();
		
		String sql;
		books.insertInfo("222", "jack", "abc");
		books.insertInfo("123", "alpha", "go");
		books.insertInfo("111", "Men", "gef");
		System.out.println("After insert:");
		books.printfTable();
		
		
		books.updateInfo("111","rose",null);
		System.out.println("after update:");
		sql = "select * from Author";
		books.printfTable();
		
		sql = "select * from Author where id='123'";
		System.out.println("after execute search :");
		books.searchInfo(sql);
		
		System.out.println("after execute delete:");
		books.deleteInfo("123");
		sql = "select * from Author";
		books.printfTable();
		
	}
}
