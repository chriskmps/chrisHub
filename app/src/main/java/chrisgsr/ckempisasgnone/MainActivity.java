//By Christian Kempis

package chrisgsr.ckempisasgnone;

import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import java.lang.StringBuilder;

public class MainActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    final StringBuilder theText = new StringBuilder();

    public void clickButton(View v) {
        Button b = (Button) v;
        String t = b.getText().toString();
        if((t.compareTo("DEL") != 0) || (t.compareTo("CALL") !=0)){
            if(theText.length()<12) {
                theText.append(t);
            }
        }
        TextView tv = (TextView) findViewById(R.id.textView);
        tv.setText(theText);
    }

    public void clickCall(View w) {
        int strLen = theText.length();
        theText.delete(0,strLen);
        TextView ax = (TextView) findViewById(R.id.textView);
        ax.setText(theText);
    }

    public void clickDel(View x) {
        int strLen2 = theText.length();
        if(strLen2 > 0) {
            theText.delete(strLen2 - 1, strLen2);
            TextView ax = (TextView) findViewById(R.id.textView);
            ax.setText(theText);
        }
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

}
