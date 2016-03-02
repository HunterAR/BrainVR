using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class ButtonBehaviour : MonoBehaviour {
    GameObject[] ventricles;
	int activeVentricleIndex;

	[SerializeField] private GameObject mannequin;
	[SerializeField] private GameObject head;
	[SerializeField] private Text _nameText;
	[SerializeField] private GameObject _menuPanel;

    void Start()
    {
		// Hide all ventricles except one
        ventricles = GameObject.FindGameObjectsWithTag("Ventricle");
        for (int i = 1; i < ventricles.Length; i++)
        {
            Debug.Log("come in here");
            ventricles[i].SetActive(false);
        }
		activeVentricleIndex = 0;

		// Show ventricle name
		_nameText.text = ventricles [activeVentricleIndex].transform.parent.name;

		_menuPanel.SetActive (false);
    }

	public void MenuClick()
	{
		// Toggle menu display
		_menuPanel.SetActive (!_menuPanel.activeInHierarchy);
	}


    public void RightClick()
    {
		ventricles [activeVentricleIndex].SetActive (false);
		activeVentricleIndex = (activeVentricleIndex + 1) % ventricles.Length;
		ventricles [activeVentricleIndex].SetActive (true);
		_nameText.text = ventricles [activeVentricleIndex].transform.parent.name;
    }

    public void LeftClick()
    {

		ventricles [activeVentricleIndex].SetActive (false);
		activeVentricleIndex = (activeVentricleIndex - 1 + ventricles.Length) % ventricles.Length;
		ventricles [activeVentricleIndex].SetActive (true);
		_nameText.text = ventricles [activeVentricleIndex].transform.parent.name;
    }

	public void PositionXChanged(float value) {
		Vector3 position = mannequin.transform.localPosition;
		position.x = value;
		mannequin.transform.localPosition = position;
	}

	public void PositionYChanged(float value) {
		Vector3 position = mannequin.transform.localPosition;
		position.y = value;
		mannequin.transform.localPosition = position;
	}

	public void PositionZChanged(float value) {
		Vector3 position = mannequin.transform.localPosition;
		position.z = value;
		mannequin.transform.localPosition = position;
	}

	public void TransparencyVentriclesChanged(float value) {
		Renderer[] renderers = ventricles [activeVentricleIndex].GetComponentsInChildren<Renderer> ();
		for (int i = 0; i < renderers.Length; i++) {
			Color color = renderers [i].material.color;
			color.a = value;
			renderers [i].material.color = color;
		}
	}

	public void TransparencyHeadChanged(float value) {
		Color color = head.GetComponent<Renderer> ().material.color;
		color.a = value;
		head.GetComponent<Renderer> ().material.color = color;
	}

	public void ScaleValueChanged(float value) {
		mannequin.transform.localScale = new Vector3 (value, value, value);
	}
}
