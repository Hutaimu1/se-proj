import java.util.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Wordladder {

	/*find the path of word ladder. and return a stack*/
	public static Stack<String> wordLadder(String start,String end,Set<String>dict){
		int length = start.length();
		Queue<Stack<String>> ladderqueue = new LinkedList<Stack<String>>();
		Stack<String> wordladder = new Stack<String>();
		wordladder.push(start);
		ladderqueue.add(wordladder);
		
		/*to find all words which are the same length with start*/
		Set<String> possibleword = new LinkedHashSet<String>();
		for(String item:dict) {
			int ilength = item.length();
			if(ilength == length) {
				possibleword.add(item);
			}
		}
		
		while(!ladderqueue.isEmpty()) {
			Stack<String> tempstack = ladderqueue.element();
			String word = tempstack.peek();
			ladderqueue.remove();
			
			for(int i = 0; i<length; ++i) {
				char oldchar = word.charAt(i);
				for(char c = 'a'; c<'z'; ++c) {
					if(c == oldchar)
						continue;
					char[] arr = word.toCharArray();
					arr[i] = c;
					word = new String(arr);
					if(possibleword.contains(word)) {
						if(word.equals(end)) {
							possibleword.remove(end);
							Stack<String> result = tempstack;
							result.push(word);
							return result;
						}
						possibleword.remove(word);
						Stack<String> result = (Stack<String>) tempstack.clone();
						result.push(word);
						ladderqueue.add(result);
				}
					char[] arr2 = word.toCharArray();
					arr2[i] = oldchar;
					word = new String(arr2);
			}
		}
	}
		Stack<String> emptystack = null;
		return emptystack;
}
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		  Scanner scanner = new Scanner(System.in);
		  System.out.println("Please input the file name:");  
		  String uri = scanner.next();
		  File file = new File(uri);
		  while(!file.exists()) {
			  System.out.println("Cannot find the file path!");
			  System.out.println("Please try to input the file name again:"); 
			  uri = scanner.next();
			  file = new File(uri);
		  }
		  FileInputStream fis = new FileInputStream(uri);
		  InputStreamReader isr = new InputStreamReader(fis);
		  BufferedReader br = new BufferedReader(isr);
		  Set<String> dict = new LinkedHashSet<String>();
		  String str = null;  
	      while((str = br.readLine()) != null)  
	        {    
	    	    str.toLowerCase();
	            dict.add(str);
	        } 
	      fis.close();  
	      br.close();
	      while(true) {
	    	  Scanner word1 = new Scanner(System.in);
	          System.out.println("Please enter Word#1 (or enter to quit):");
	          String startword = word1.nextLine();
	          if(startword.length() == 0) {
	        	  System.out.println("Have a nice day!");
	    	      System.exit(0);
	          }
	          System.out.println("Please enter Word#2 (or enter to quit):");
	          String endword = word1.nextLine();
	          if(endword.length() == 0) {
	        	  System.out.println("Have a nice day!");
	    	      System.exit(0);
	          } 
	      
	          startword.toLowerCase();
	          endword.toLowerCase();
	          if(!(dict.contains(startword) && dict.contains(endword)))
	        	  System.out.println("The two words must be found in the dictionary.");
	          else {
	        	  if(startword.equals(endword))
		    	  System.out.println("The two words must be different.");
	        	  else {
	        		  if(startword.length() != endword.length()) 
		    	      System.out.println("The two words must be the same length.");  
	        		  else {
	        			  Stack<String> result = wordLadder(startword,endword,dict);
	                      if(result == null)
	    	              System.out.println("No word ladder found from " + endword + " to " + startword);
	                      else {
	                    	  System.out.println("A ladder from " + endword + " back to " + startword + ":");
	    	                  System.out.println(result.peek());
	    	                  result.pop();
	                          while(!result.empty()) {
	                        	  System.out.println(result.peek());
	        	                  result.pop();
	                              }
	                      } 
	              }
	          }
	          }
	      }
	}
 }   

