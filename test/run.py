from Crypto import Random
from Crypto.Cipher import PKCS1_v1_5, PKCS1_OAEP
from Crypto.Hash import SHA256, HMAC
from Crypto.PublicKey import RSA

class SSE:
  def __init__(self):
    print('Initializing')
    self.ur = PKCS1_OAEP.new(RSA.generate(1024))
    self.ul = PKCS1_OAEP.new(RSA.generate(1024))
    self.prf = HMAC.new(Random.new().read(32), msg=None, digestmod=SHA256)

  def upleft(self, trapdoor, lx, ly):
    trapdoor = self.ul.encrypt(trapdoor)
    lx += 1
    ly //= 2
    return trapdoor, lx, ly

  def upright(self, trapdoor, lx, ly):
    trapdoor = self.ur.encrypt(trapdoor)
    lx += 1
    ly //= 2
    return trapdoor, lx, ly
  
  def downleft(self, trapdoor, lx, ly):
    trapdoor = self.ur.decrypt(trapdoor)
    lx -= 1
    ly *= 2
    return trapdoor, lx, ly

  def downright(self, trapdoor, lx, ly):
    trapdoor = self.ul.decrypt(trapdoor)
    lx -= 1
    ly = ly*2 + 1
    return trapdoor, lx, ly

  def createTrapdoor(self, word):
    self.prf.update(word)
    return self.prf.hexdigest()

sse = SSE()
word = 'hello world'

trapdoor = sse.createTrapdoor(word)

def getTrapdoor01(trapdoor):
  lx, ly = 0, 0
  trapdoor10, lx, ly = sse.upright(trapdoor, lx, ly)
  trapdoor01, lx, ly = sse.downright(trapdoor10, lx, ly)
  return trapdoor01

print getTrapdoor01(trapdoor)
print getTrapdoor01(trapdoor)