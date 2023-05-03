# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: onny <onny@project-insanity.org>

pkgname=python-passlib
pkgver=1.7.4
pkgrel=6
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
sha512sums=('350bd6da5ac57e6c266ffe8bf9684c8c2cce3fc6b513eb6c7bc1b302d2d8a1b701e9c01c953782520a2ac37b7ec1f6d7bd5855f99f6ee0e2dbbf33f2d49a9530')

check() {
  export PASSLIB_TEST_MODE=full

  cd "$srcdir"/passlib-$pkgver
  python setup.py nosetests || echo "https://bitbucket.org/ecollins/passlib/issues/98/passlibextdjango-with-django-1112-fails"
}

package() {
  cd passlib-$pkgver
  python setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
