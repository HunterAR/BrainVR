using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class ButtonBehaviour : MonoBehaviour {
	// Serialized fields
	[SerializeField] private GameObject mannequin;
	[SerializeField] private GameObject head;
	[SerializeField] private Text nameText;
	[SerializeField] private GameObject menuPanel;
	[SerializeField] private Slider positionXSlider;
	[SerializeField] private Slider positionYSlider;
	[SerializeField] private Slider positionZSlider;
	[SerializeField] private Slider transparencyVentriclesSlider;
	[SerializeField] private Slider transparencyHeadSlider;
	[SerializeField] private Slider scaleSlider;
	[SerializeField] private Slider tiltSlider;

    GameObject[] ventricles;
    int activeVentricleIndex;

    void Start()
    {
        activeVentricleIndex = 0;

        ventricles = GameObject.FindGameObjectsWithTag("Ventricle");
        SortAlphabetLength alphaLen = new SortAlphabetLength();
        
        foreach (GameObject ventricle in ventricles)
        {
            ventricle.SetActive(false);
        }
        System.Array.Sort(ventricles, (x, y) => alphaLen.Compare(x.transform.parent.name, y.transform.parent.name));

        ventricles[0].SetActive(true);
        // Show ventricle name
        nameText.text = ventricles [activeVentricleIndex].transform.parent.name;

		// Load saved values
		Slider[] sliders = GameObject.FindObjectsOfType(typeof(Slider)) as Slider[];
		foreach (Slider slider in sliders) {
			slider.value = PlayerPrefs.GetFloat (slider.name, slider.value);
		}

		menuPanel.SetActive (false);
    }

	public void MenuClick()
	{
		// Toggle menu display
		menuPanel.SetActive (!menuPanel.activeInHierarchy);
	}


    public void RightClick()
    {
		ShowNextVentricle ((activeVentricleIndex + 1) % ventricles.Length);
    }

    public void LeftClick()
    {
		ShowNextVentricle((activeVentricleIndex - 1 + ventricles.Length) % ventricles.Length);
    }

    void ShowNextVentricle(int nextVentricleIndex)
    {
        ventricles[activeVentricleIndex].SetActive(false);
        activeVentricleIndex = nextVentricleIndex;
        ventricles[activeVentricleIndex].SetActive(true);
        nameText.text = ventricles[activeVentricleIndex].transform.parent.name;

        // Apply last transparency to new ventricle; other properties propagate already
        TransparencyVentriclesChanged(transparencyVentriclesSlider.value);
    }

    public void PositionXChanged(float value) {
		Vector3 position = mannequin.transform.localPosition;
		position.x = value;
		mannequin.transform.localPosition = position;
		PlayerPrefs.SetFloat (positionXSlider.name, value);
	}

	public void PositionYChanged(float value) {
		Vector3 position = mannequin.transform.localPosition;
		position.y = value;
		mannequin.transform.localPosition = position;
		PlayerPrefs.SetFloat (positionYSlider.name, value);
	}

	public void PositionZChanged(float value) {
		Vector3 position = mannequin.transform.localPosition;
		position.z = value;
		mannequin.transform.localPosition = position;
		PlayerPrefs.SetFloat (positionZSlider.name, value);
	}

	public void TransparencyVentriclesChanged(float value) {
		Debug.Log ("transparency");
		Renderer[] renderers = ventricles [activeVentricleIndex].GetComponentsInChildren<Renderer> ();
		for (int i = 0; i < renderers.Length; i++) {
			Color color = renderers [i].material.color;
			color.a = value;
			renderers [i].material.color = color;
		}
		PlayerPrefs.SetFloat (transparencyVentriclesSlider.name, value);
	}

	public void TransparencyHeadChanged(float value) {
		Color color = head.GetComponent<Renderer> ().material.color;
		color.a = value;
		head.GetComponent<Renderer> ().material.color = color;
		PlayerPrefs.SetFloat (transparencyHeadSlider.name, value);
	}

	public void ScaleValueChanged(float value) {
		mannequin.transform.localScale = new Vector3 (value, value, value);
		PlayerPrefs.SetFloat (scaleSlider.name, value);
	}

	public void TiltValueChanged(float value) {
		Vector3 rotation = mannequin.transform.localEulerAngles;
		rotation.x = value;
		mannequin.transform.localEulerAngles = rotation;
		PlayerPrefs.SetFloat (tiltSlider.name, value);
	}
}
