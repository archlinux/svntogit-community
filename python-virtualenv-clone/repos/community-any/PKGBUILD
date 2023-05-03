# Maintainer: Evangelos Foutras <evangelos@foutrelis.com

pkgname='python-virtualenv-clone'
pkgver=0.5.7
pkgrel=4
pkgdesc="A script for cloning a non-relocatable virtualenv."
arch=('any')
url="https://github.com/edwardgeorge/virtualenv-clone"
license=('GPL')
depends=('python')
makedepends=('python-setuptools')
options=('!emptydirs')
source=(https://files.pythonhosted.org/packages/source/v/virtualenv-clone/virtualenv-clone-$pkgver.tar.gz)
sha256sums=('418ee935c36152f8f153c79824bb93eaf6f0f7984bae31d3f48f350b9183501a')

package() {
  cd "$srcdir/virtualenv-clone-$pkgver"
  python3 setup.py install --root="$pkgdir" -O1
}

# vim:set ts=2 sw=2 et:
