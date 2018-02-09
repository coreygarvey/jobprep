'''

Singly linked list in Python

'''

import sys

class Node:

	def __init__(self, data=None, next_node=None):

		self.data = data

		self.next_node = next_node


	def get_data(self):

		return self.data


class LinkedList:

	def __init__(self, head=None):

		self.head = head

	def insert(self, data=None):

		newNode = Node(data)

		current = self.head

		while current.next_node != None:

			current = current.next_node

		current.next_node = newNode

		return

	def pop(self):

		current = self.head

		while current.next_node.next_node != None:

			current = current.next_node

		tmp = current.next_node.next_node

		del current.next_node

		current.next_node = tmp

		return


	def deleteNode(self, data):

		current = self.head

		if(current.data == data):

			tmp = current.next_node

			del current

			self.head = tmp

			print "Deleted your node, here's the new LL: "

			self.printLL()

			return

		while(current.next_node != None):

			if(current.next_node.data == data):

				tmp = current.next_node.next_node

				del current.next_node

				current.next_node = tmp

				print "Deleted your node, here's the new LL: "

				self.printLL()

				return

			current = current.next_node

		print "Sorry, no node with that data"

		return

	
	def get_length(self):

		count = 0

		current = self.head

		while current != None:

			current = current.next_node

			count += 1

		return count


	def printLL(self):

		current = self.head

		outputString = ""

		while current.next_node != None:

			outputString += str(current.data) + "-"

			current = current.next_node

		outputString += str(current.data)

		print outputString

		return


#if __name__ == "__main__":
def main():

	filename = sys.argv[0]

	myNode = Node(1)

	myLL = LinkedList(myNode)

	myLL.insert(2)

	myLL.insert(3)

	myLL.insert(4)

	myLL.insert(5)

	myLL.printLL()

	myLL.pop()

	myLL.insert(6)

	myLL.printLL()

	deleteMe = int(raw_input("Enter a node to delete: "))

	myLL.deleteNode(deleteMe)

	inputNode = raw_input("Enter a node to input (None to exit): ")

	while inputNode != "None":

		myLL.insert(inputNode)

		print "Your new LinkedList: "

		myLL.printLL()

		inputNode = raw_input("Enter a node to input (None to exit): ")


main()