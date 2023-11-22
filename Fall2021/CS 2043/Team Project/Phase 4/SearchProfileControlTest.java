import static org.junit.jupiter.api.Assertions.*;

import java.util.ArrayList;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class SearchProfileControlTest {
	
	private DataManager dm;
	private SearchProfileControl control;

	@BeforeEach
	void setUp() throws Exception {
		dm = new DataManager();
		control = new SearchProfileControl(dm);
	}
	
	@Test
	void testProcessProfileSearchCase1() {
		ArrayList<String> keywords =  new ArrayList<String>();
		keywords.add("jsdfa");
		keywords.add(" 0");
		ArrayList<ProfileInfoObject> test = control.processProfileSearch(keywords);
		System.out.println(test);
		ArrayList<String> expected = new ArrayList<String>();
		assertArrayEquals(expected.toArray(), test.toArray());
		
		
	}

	@Test
	void testProcessProfileSearchCase2() {
		ArrayList<String> keywords =  new ArrayList<String>();
		keywords.add("bdouce10");
		String terminator = " 0";
		keywords.add(terminator);
		ArrayList<ProfileInfoObject> test = control.processProfileSearch(keywords);
		ArrayList<String> testString = new ArrayList<String>();
		ArrayList<String> expected = new ArrayList<String>();
		
		for (int i = 0; i < test.size(); i++) {
			testString.add(test.get(i).userID);
			testString.add(test.get(i).userName);
			testString.add(test.get(i).displayName);
		}
		
		expected.add("1");
		expected.add("BrendanD7");
		expected.add("bdouce10");
		assertArrayEquals(expected.toArray(), testString.toArray());
	}

}
