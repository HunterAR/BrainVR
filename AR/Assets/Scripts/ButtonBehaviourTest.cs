using System;
using System.Collections.Generic;
using UnityEngine;
using UnityTest;

[IntegrationTest.DynamicTestAttribute("ButtonBehaviourTest")]
[IntegrationTest.SucceedWithAssertions]
public class ButtonBehaviourTest : MonoBehaviour
{
	static int frameCheckFrequency = 2000;

	public GameObject canvas;
	public GameObject mannequin;

	public void Awake()
	{
		// Assert the mannequin's x, y, and z positions are the same as the respective slider values
		GameObject positionXSlider = GameObject.Find ("x Slider");
		IAssertionComponentConfigurator configurator;
		AssertionComponent.Create<FloatComparer> (out configurator, CheckMethod.Update, positionXSlider, "Slider.value", mannequin, "transform.position.x");
		configurator.UpdateCheckRepeatFrequency = frameCheckFrequency;
		
		GameObject positionYSlider = GameObject.Find ("y Slider");
		AssertionComponent.Create<FloatComparer> (out configurator, CheckMethod.Update, positionYSlider, "Slider.value", mannequin, "transform.position.y");
		configurator.UpdateCheckRepeatFrequency = frameCheckFrequency;

		GameObject positionZSlider = GameObject.Find ("z Slider");
		AssertionComponent.Create<FloatComparer> (out configurator, CheckMethod.Update, positionZSlider, "Slider.value", mannequin, "transform.position.z");
		configurator.UpdateCheckRepeatFrequency = frameCheckFrequency;

		// Assert one component of the mannequin's scale is the same as the scale slider value
		GameObject scaleSlider = GameObject.Find ("Scale Slider");
		AssertionComponent.Create<FloatComparer> (out configurator, CheckMethod.Update, scaleSlider, "Slider.value", mannequin, "transform.localScale.x");
		configurator.UpdateCheckRepeatFrequency = frameCheckFrequency;

		// Assert x component of the mannequin's rotation is the same as the tilt slider value
		GameObject tiltSlider = GameObject.Find ("Tilt Slider");
		AssertionComponent.Create<FloatComparer> (out configurator, CheckMethod.Update, tiltSlider, "Slider.value", mannequin, "transform.localEulerAngles.x");
		configurator.UpdateCheckRepeatFrequency = frameCheckFrequency;
	}
}
