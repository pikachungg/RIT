package com.example.leagueoflegends

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView

class DisplayFragment : Fragment() {
    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_display, container, false)
    }

    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        val image = view.findViewById<ImageView>(R.id.championImage)
        val name = view.findViewById<TextView>(R.id.championText)

        image.setImageResource(requireArguments().getInt(ARG_IMG_ID))
        name.text = requireArguments().getString(ARG_TEXT_ID)
    }

    companion object {
        const val ARG_IMG_ID = "image_id"
        const val ARG_TEXT_ID = "text_id"
    }
}