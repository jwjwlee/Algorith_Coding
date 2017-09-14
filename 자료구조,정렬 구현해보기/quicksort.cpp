
void quicksort(int data[], int left, int right)
{
	int i = 0, j = 0, pivot = 0;

	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = data[left];

		do
		{
			do
			{
				i++;
			} while (data[i] < pivot);

			do
			{
				j--;
			} while (data[j] > pivot);

			if (i < j)
				swap(data[i], data[j]);			

		} while (i < j);

		swap(data[left], data[j]);
		quicksort(data, left, j - 1);		
		quicksort(data, j + 1, right);
	}
}