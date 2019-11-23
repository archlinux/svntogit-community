# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: onny <onny@project-insanity.org>

pkgname=python-passlib
pkgver=1.7.2
pkgrel=1
pkgdesc="A password hashing library for Python"
arch=('any')
url="https://code.google.com/p/passlib/"
license=('custom:BSD')
depends=("python")
optdepends=("python-fastpbkdf2: accelerate PBKDF2-based hashes"
            "python-bcrypt: accelerate Bcrypt hashes"
            "python-scrypt: accelerate SCrypt hashes")
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-bcrypt' 'python-django' 'python-fastpbkdf2' 'python-scrypt')
source=("https://pypi.io/packages/source/p/passlib/passlib-$pkgver.tar.gz")
sha512sums=('1ea0654b177b5ab2e1a7e5c3949642c34805ace6e4e4a0f82fafdb3f374edd99c667906ce598c335b668da049860648d5cbebb3e62d775898d5b0cb8cfc7bf53')

check() {
  export PASSLIB_TEST_MODE=full

  cd "$srcdir"/passlib-$pkgver
  python setup.py nosetests || warning "https://bitbucket.org/ecollins/passlib/issues/98/passlibextdjango-with-django-1112-fails"
}

package() {
  cd passlib-$pkgver
  python setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
