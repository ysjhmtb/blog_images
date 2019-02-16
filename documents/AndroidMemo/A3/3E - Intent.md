# 3E - Intent

```Java
package company.co.class_3e;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button = (Button) findViewById(R.id.btn_call);
        button.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {

        // 명시적 인텐트
        // Toast.makeText(MainActivity.this, "Click!!", Toast.LENGTH_SHORT).show();

        // 묵시적 인텐트
//        Intent intent = new Intent();
//        intent.setAction(Intent.ACTION_DIAL);
//        startActivity(intent);

        Intent intent = new Intent(MainActivity.this, CallActivity.class);
        intent.putExtra("intent-message", "game joa joa");

        startActivity(intent);
    }
}

```

<br>

```xml
<?xml version="1.0" encoding="utf-8"?>
<android.support.constraint.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".MainActivity">

    <Button
        android:id="@+id/btn_call"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="CALL" />

</android.support.constraint.ConstraintLayout>
```

<br>

```Java
package company.co.class_3e;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;

public class CallActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_call);

        String message = getIntent().getStringExtra("intent-message");
        Toast.makeText(CallActivity.this, message, Toast.LENGTH_SHORT).show();
    }
}

```

<br>

```xml
<?xml version="1.0" encoding="utf-8"?>
<android.support.constraint.ConstraintLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".CallActivity">

    <TextView
        android:textSize="36sp"
        android:text="CALL"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content" />

</android.support.constraint.ConstraintLayout>
```

<br>

