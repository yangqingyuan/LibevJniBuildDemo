package com.guanren.libevjnibuilddemo

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.TextView
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        findViewById<Button>(R.id.sample_text).let {
            it.setOnClickListener {
                Toast.makeText(application,"test",Toast.LENGTH_LONG).show()
            }
        }

        Thread {
            EvUtils.init()
        }.start()
    }

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("ev")
        }
    }
}