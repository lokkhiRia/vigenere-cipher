#include<iostream>
using namespace std;

string Encrypt(string message, string key)
{
    string encrypted ="";
    int key_len=key.length();
    for(int i=0;i<message.length();i++)
    {
        int plain_char=message[i];
        int key_char=key[i%key_len];

        int encryptionmessage = (plain_char+key_char)%26;
        encrypted +=encryptionmessage + 'A';

    }
    return encrypted;


}

string Decrypt(string message, string key)
{
    string decrypted ="";
    int key_len=key.length();
    for(int i=0;i<message.length();i++)
    {
        int cipher_char=message[i];
        int key_char=key[i%key_len];

        int encryptionmessage = (cipher_char-key_char +26)%26;
        decrypted +=encryptionmessage + 'A';

    }
    return decrypted;


}

int main()
{

    string message,key;

    cout<<"Enter a message for encrypt: ";
    cin>>message;

    cout<<"Enter a key for encryption: ";
    cin>>key;

    string encrypted=Encrypt(message,key);
    cout<<"Encrypted message:"<<encrypted<<endl;


    string decrypted=Decrypt(encrypted,key);
    cout<<"Encrypted message:"<<decrypted<<endl;

    return 0;

}
