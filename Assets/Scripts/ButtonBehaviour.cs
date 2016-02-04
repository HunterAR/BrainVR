using UnityEngine;
using System.Collections;

public class ButtonBehaviour : MonoBehaviour {
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

    public void RightClick()
    {
        for (int i = 0; i < ventricles.Length; i++)
        {
            if(ventricles[i].activeSelf == true)
            {
                ventricles[i].SetActive(false);
                if (i == ventricles.Length-1)
                {
                    ventricles[0].SetActive(true);
                }
                else
                {
                    ventricles[i+1].SetActive(true);
                }
                break;
            }
        }
    }

    public void LeftClick()
    {
        for (int i = 0; i < ventricles.Length; i++)
        {
            if (ventricles[i].activeSelf == true)
            {
                ventricles[i].SetActive(false);
                if (i == 0)
                {
                    ventricles[ventricles.Length - 1].SetActive(true);
                }
                else
                {
                    ventricles[i - 1].SetActive(true);
                }
                break;
            }
        }
    }
}
