# Maintainer: Kyle Keen <keenerd@gmail.com>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Andy Weidenbaum <archbaum@gmail.com>

pkgname=python-prompt_toolkit
_name=prompt_toolkit
pkgver=3.0.31
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
sha256sums=('9ada952c9d1787f52ff6d5f3484d0b4df8952787c087edf6a1f7c2cb1ea88148')

build() {
  cd "$_name-$pkgver"
  python setup.py build
}

check() {
  cd "$_name-$pkgver"
  PYTHONPATH=src PYTHONDONTWRITEBYTECODE=1  python -m pytest
}

package() {
  cd "$_name-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
