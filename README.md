# DataStoreCDR
This is a file-based key-value data store that supports the basic CRD (create, read, and delete) operations. This data store is meant to be used as a local storage for one single process on one laptop.

The data store will support the following functional requirements.

1. It can be initialized using an optional file path. If one is not provided,it will reliably create itself in a reasonable location on the laptop.
2. A new key-value pair will be added to the data store using the Create operation. The key always a string - capped at 32chars.
3. If Create is invoked for an existing key, an appropriate error will be shown.
4. A Read operation on a key can be performed by providing the key, and receiving the value in response, as a JSON object.
5. A Delete operation can be performed by providing the key .
6. Appropriate error responses will always be returned to a client if it uses the data store in unexpected ways or breaches any limits.


The data store will also support the following non-functional requirements.

1. The size of the file storing data will never exceed 1GB.
2. A client process is allowed to access the data store using multiple threads, if it desires to The data store is thread-safe.
3. The client will bear as little memory costs as possible to use this data store, while deriving maximum performance with respect to response times for accessing the data store.

Languages: C++





![Screenshot (195)](https://user-images.githubusercontent.com/74704102/103415145-e3985e00-4ba6-11eb-8df5-0b4bc3626333.png)
![Screenshot (196)](https://user-images.githubusercontent.com/74704102/103415149-e5622180-4ba6-11eb-9a6c-ef4ec615274e.png)
![Screenshot (197)](https://user-images.githubusercontent.com/74704102/103415153-e6934e80-4ba6-11eb-87f1-941448142d0c.png)
![Screenshot (198)](https://user-images.githubusercontent.com/74704102/103415154-e7c47b80-4ba6-11eb-99fe-2881294db3af.png)
![Screenshot (199)](https://user-images.githubusercontent.com/74704102/103415155-e98e3f00-4ba6-11eb-964c-8f7b3d0d0295.png)
