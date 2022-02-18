package com.guanren.libevjnibuilddemo

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.Toast
import java.util.*

class MainActivity : AppCompatActivity() {
    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("ev")
        }

        var isInit:Boolean = false
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        findViewById<Button>(R.id.test_ev).let {
            it.setOnClickListener {
                if(!isInit) {
                    Thread {
                        isInit = true
                        EvUtils.initEv()
                    }.start()
                }
            }
        }


        var random = Random(1)
        findViewById<Button>(R.id.test_event).let {
            it.setOnClickListener {
                if(!isInit){
                    Toast.makeText(applicationContext,"请先点击InitEvn初始化",Toast.LENGTH_LONG).show()
                }else {
                    val sec = random.nextInt(10)
                    Toast.makeText(applicationContext,"设置了定时器时间间隔为$sec 秒，将会在$sec 秒后控制台中打印log",Toast.LENGTH_LONG).show()
                    EvUtils.testTimerAgain(sec)
                }
            }
        }
    }
}