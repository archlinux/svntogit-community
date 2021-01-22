# Maintainer: Kyle Keen <keenerd@gmail.com>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Andy Weidenbaum <archbaum@gmail.com>

pkgname=python-prompt_toolkit
_name=prompt_toolkit
pkgver=3.0.13
pkgrel=1
pkgdesc="Library for building powerful interactive command lines in Python"
arch=('any')
depends=('python-pygments'
         'python-wcwidth')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
url="https://github.com/jonathanslenders/python-prompt-toolkit"
license=('BSD')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/p/$_name/$_name-$pkgver.tar.gz")
sha256sums=('e2d04e0e4de0c0a8b67db89a5be6dcf81fed6ca7e8c4affca8b7a5b8595c19dd')

build() {
  cd "$_name-$pkgver"
  python setup.py build
}

check() {
  cd "$_name-$pkgver"
  python -m pytest
}

package() {
  cd "$_name-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
