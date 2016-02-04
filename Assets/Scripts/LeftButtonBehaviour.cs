/*using UnityEngine;
using System.Collections;

public class LeftButtonBehaviour : MonoBehaviour {
    public GameObject[] ventricles;

    void Start()
    {
        ventricles = GameObject.FindGameObjectsWithTag("Ventricle");
        for (int i = 0; i < ventricles.Length - 1; i++)
        {
            Debug.Log("come in here");
            ventricles[i].SetActive(false);
        }
    }

    public void Click()
    {
        for (int i = 0; i < ventricles.Length; i++)
        {
            if (ventricles[i].GetComponent<MeshRenderer>().enabled == true)
            {
                ventricles[i].GetComponent<MeshRenderer>().enabled = false;
                if (i == 0)
                {
                    ventricles[ventricles.Length - 1].GetComponent<MeshRenderer>().enabled = true;
                }
                else
                {
                    ventricles[i - 1].GetComponent<MeshRenderer>().enabled = true;
                }
                break;
            }
        }
    }
}
*/