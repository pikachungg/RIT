package com.example.lifecycleexplore

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.PersistableBundle
import com.example.lifecycleexplore.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater);

        setContentView(binding.root)

        if (savedInstanceState != null){
            binding.textView.text = savedInstanceState.getCharSequence("mytest")
        }

        binding.textView.append("\n")
    }
    override fun onStart(){
        super.onStart()
        binding.textView.append("Start\n")
    }

    override fun onSaveInstanceState(outState: Bundle) {
        super.onSaveInstanceState(outState)
        outState.putCharSequence("my text", binding.textView.text)
    }

    override fun onPause() {
        super.onPause()
        binding.textView.append("pause\n")
    }

    override fun onResume() {
        super.onResume()
        binding.textView.append("Resume\n")
    }

    override fun onStop(){
        super.onStop()
        binding.textView.append("Stop\n")
    }

    override fun onRestart() {
        super.onRestart()
        binding.textView.append("Restart\n")
    }

    override fun onDestroy() {
        super.onDestroy()
        binding.textView.append("Destroy\n")
    }
}