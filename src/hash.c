# define get16bits(d) (*((const uint16_t *) (d)))

unsigned int strlen(char *str)
{
	int		index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

unsigned int compute_hash(char *key, unsigned int hash, unsigned int len)
{
	while (len > 0)
	{
		hash += get16bits(key);
		tmp = (get16bits(key + 2) << 11) ^ hash; 
		hash = (hash << 16) ^ tmp;
		key += 2 * sizeof(short unsigned int);
		hash += hash >> 11;
	}
	return (hash);
}

unsigned int handle_end(char *key, unsigned int hash, unsigned int rem)
{
	if (rem == 3)
	{
		hash += get16bits (key);
		hash ^= hash << 16;
		hash ^= ((signed char)key[sizeof (uint16_t)]) << 18;
		hash += hash >> 11;
	}
	else if (rem == 2)
	{
		hash += get16bits (key);
		hash ^= hash << 11;
		hash += hash >> 17;

	}
	else if (rem == 1)
	{
		hash += (signed char)*key;
		hash ^= hash << 10;
		hash += hash >> 1;
	}
	return (hash);
}

unsigned int superfasthash(char *key)
{
	unsigned int	hash;
	unsigned int	len;
	int				rem;

	if (!(len = strlen(key)))
		return (0);
	rem = len & 3;
	hash = compute_hash(key, len, len >> 2);
	key += 2 * sizeof(short unsigned int) * (len >> 2);
	hash = handle_end(key, hash, rem);
	hash ^= hash << 3;
	hash += hash >> 5;
	hash ^= hash << 4;
	hash += hash >> 17;
	hash ^= hash << 25;
	hash += hash >> 6;
	return (hash);
}
