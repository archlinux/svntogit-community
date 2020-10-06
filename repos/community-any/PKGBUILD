# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: onny <onny@project-insanity.org>

pkgname=python-passlib
pkgver=1.7.3
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
sha512sums=('1964f6ef30f0c98d9688e7dff96f31f1a9ae409c78703169e6690ca228fb96d590c20f03dfca7c01d8091c3384ffb58a40c866889c8195234657e11f140f39d9')

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
