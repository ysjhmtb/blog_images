# Android Notification

책에서 안드로이드 알람에 대해 읽다가 작동하지 않음을 확인하고 다음의 코드를 확인.

<br>

[How to create a notification with NotificationCompat.Builder in Android?](https://www.tutorialspoint.com/how-to-create-a-notification-with-notificationcompat-builder-in-android)

<br>

```xml
<?xml version = "1.0" encoding = "utf-8"?>
<android.support.constraint.ConstraintLayout xmlns:android = "http://schemas.android.com/apk/res/android"
   xmlns:app = "http://schemas.android.com/apk/res-auto"
   xmlns:tools = "http://schemas.android.com/tools"
   android:layout_width = "match_parent"
   android:layout_height = "match_parent"
   tools:context = ".MainActivity">
   <Button
      android:id = "@+id/button"
      android:layout_width = "wrap_content"
      android:layout_height = "wrap_content"
      android:text = "Click"
      app:layout_constraintBottom_toBottomOf = "parent"
      app:layout_constraintLeft_toLeftOf = "parent"
      app:layout_constraintRight_toRightOf = "parent"
      app:layout_constraintTop_toTopOf = "parent" />
</android.support.constraint.ConstraintLayout>
```

<br>

```java
package com.example.andy.myapplication;
import android.annotation.SuppressLint;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.os.Build;
import android.support.annotation.RequiresApi;
import android.support.v4.app.NotificationCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Switch;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity implements View.OnClickListener {
   @Override
   protected void onCreate(Bundle savedInstanceState) {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.activity_main);
      Button button=findViewById(R.id.button);
      button.setOnClickListener(this);
   }
   @RequiresApi(api = Build.VERSION_CODES.O)
   @Override
   public void onClick(View v) {
      switch (v.getId()) {
         case R.id.button:
            notificationDialog();
            break;
      }
   }
   @RequiresApi(api = Build.VERSION_CODES.O)
   private void notificationDialog() {
      NotificationManager notificationManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
      String NOTIFICATION_CHANNEL_ID = "tutorialspoint_01";
      if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
         @SuppressLint("WrongConstant") NotificationChannel notificationChannel = new NotificationChannel(NOTIFICATION_CHANNEL_ID, "My Notifications", NotificationManager.IMPORTANCE_MAX);
         // Configure the notification channel.
         notificationChannel.setDescription("Sample Channel description");
         notificationChannel.enableLights(true);
         notificationChannel.setLightColor(Color.RED);
         notificationChannel.setVibrationPattern(new long[]{0, 1000, 500, 1000});
         notificationChannel.enableVibration(true);
         notificationManager.createNotificationChannel(notificationChannel);
      }
      NotificationCompat.Builder notificationBuilder = new NotificationCompat.Builder(this, NOTIFICATION_CHANNEL_ID);
      notificationBuilder.setAutoCancel(true)
         .setDefaults(Notification.DEFAULT_ALL)
         .setWhen(System.currentTimeMillis())
         .setSmallIcon(R.mipmap.ic_launcher)
         .setTicker("Tutorialspoint")
       //.setPriority(Notification.PRIORITY_MAX)
         .setContentTitle("sample notification")
         .setContentText("This is sample notification")
         .setContentInfo("Information");
       notificationManager.notify(1, notificationBuilder.build());
  }
}
```

<br>

왜 책의 내용은 작동하지 않았을까?

<br>

[[안드로이드/Android]8.0 오레오 알림채널(Notification Channel) 대응하기](https://gun0912.tistory.com/77)

<br>

> 오레오에서 Notification Channel을 만들어 주지 않으면 알림이 오지 않습니다.

<br>

**!!!!**

<br>

