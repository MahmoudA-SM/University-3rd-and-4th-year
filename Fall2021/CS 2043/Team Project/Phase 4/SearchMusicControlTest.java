import static org.junit.jupiter.api.Assertions.*;

import java.util.ArrayList;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class SearchMusicControlTest {
	private DataManager dm;
	private SearchMusicControl control;
	
	@BeforeEach
	void setUp() throws Exception {
		dm = new DataManager();
		control = new SearchMusicControl(dm);
	}
	
	@Test
	void testHandleSearchMusicCase1() {
		ArrayList<AccountObject> test = control.handleSearchMusic("88");
		
		ArrayList<AccountObject> expected = new ArrayList<AccountObject>();
		assertArrayEquals(expected.toArray(),test.toArray());		
	}

	@Test
	void testHandleSearchMusicCase2() {
		ArrayList<AccountObject> test = control.handleSearchMusic("Gerald");
		ArrayList<String> testString = new ArrayList<String>();
		ArrayList<String> expected = new ArrayList<String>();
		expected.add("1");
		expected.add("bdouce10");
		expected.add("BrendanD7");
		expected.add("2");
		expected.add("Seventy");
		expected.add("Brendan");
		expected.add("3");
		expected.add("Seventy");
		expected.add("Brendan");
		expected.add("4");
		expected.add("\" displayName \"");
		expected.add("\" username  \"");
		expected.add("5");
		expected.add("wadwdwa");
		expected.add("dwdwad");
		expected.add("9");
		expected.add("Brendan");
		expected.add("Brendan");
		expected.add("10");
		expected.add("DEEE@D");
		expected.add("Brendan");
		expected.add("11");
		expected.add(" doucette");
		expected.add("bdouce10");
		expected.add("12");
		expected.add(" doucette");
		expected.add("bdouce10");
		expected.add("13");
		expected.add(" turnip");
		expected.add("turnip");
		expected.add("14");
		expected.add("turnip");
		expected.add("turnip");
		expected.add("15");
		expected.add("\" displayName \"");
		expected.add("\" username  \"");
		for (int i = 0; i < test.size(); i++) {
			testString.add(test.get(i).accountID);
			testString.add(test.get(i).displayName);
			testString.add(test.get(i).username);
		}


		
		assertArrayEquals(expected.toArray(), testString.toArray());
	}

}
