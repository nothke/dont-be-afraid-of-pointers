using System;
using System.Collections.Generic;

struct Vector3 {
    public float x;
    public float y;
    public float z;
}

class Person {
    string name;
}

class Program
{
    static void Main(string[] args)
    {
        int i = 3;
        Vector3 vec = new Vector3();
        Vector3 vec = default;
        
        {
            Vector3 vec2 = default;
            // no way to reference out of scope
        }

    }
}